#include "precomp.h"
#include "State.h"
#include "GameObject.h"
#include "MainMenu.h"
#include "Engine.h"
#include "DebugTool.h"
#include <assert.h>
#include <ClanLib/application.h>

Engine::Engine(void):
	setup_core(),
	setup_display(),
	setup_gl(),
	quit(false),
	fps(0),
	deltaTime(0),
	windowWidth(0),
	windowHeight(0),
	graphicContext(),
	window(),
	keyboard(),
	mouse(),
	resourceManager(),
	frameRate(0),
	lustUpdate(0),
	resourceManagerExists(false),
	fileSystem(),
	stateStack(),
	quitHandler(),
	Debugger()
{
	quit = false;
	fps = 0;
	resourceManagerExists = false;
	windowWidth = 800;
	windowHeight = 600;

	window = CL_DisplayWindow("Hello World", windowWidth, windowHeight);
	graphicContext = window.get_gc();
	keyboard = window.get_ic().get_keyboard();
	mouse = window.get_ic().get_mouse();
	frameRate = 60;	
	lustUpdate = CL_System::get_time();
	quitHandler = keyboard.sig_key_down().connect(this, &Engine::QiteListener);
	Debugger = std::shared_ptr<DebugTool>(new DebugTool);
	PushState(new MainMenu);
}

Engine::~Engine(){}

Engine &Engine::GetEngine(){
	static Engine Instance;
	return Instance;
}

void Engine::Draw(void){
	graphicContext.clear();
	stateStack.back()->Draw();
	Debugger->Draw();
	window.flip();
}

void Engine::Update(void){
	CL_KeepAlive::process();
	fps = (int)CountFps();
	if(fps > frameRate)
	{
		return;
	}
	stateStack.back()->Update();
	Draw();
	lustUpdate = CL_System::get_time();
	Debugger->Update();
}

int Engine::Loop(void){
	try
	{
		while (!quit){
			Update();
		}
		Quit();
	}
	catch(CL_Exception &exception)
	{
		// Create a console window for text-output if not available
		CL_ConsoleWindow console("Console", 80, 160);
		CL_Console::write_line("Exception caught: " + exception.get_message_and_stack_trace());
		console.display_close_message();
		return -1;
	}
	return 0;
}

const float Engine::CountFps(void){
	int curTime = CL_System::get_time();
	deltaTime = curTime - lustUpdate;
	if(deltaTime < 1){
		return 1000.0f;
	}
	return 1000.0f/deltaTime;
}

void Engine::PushState(State *rNewState)
{
	assert(rNewState != nullptr);

	if(!stateStack.empty()){
		stateStack.back()->Pause();
	}

	stateStack.push_back(StatePtr (rNewState));
	stateStack.back()->Initialize();
}

void Engine::PopState(void){
	if(!stateStack.empty()){
		stateStack.back()->Pause();
		stateStack.back()->Cleanup();
		stateStack.pop_back();

		if(!stateStack.empty()){
			stateStack.back()->Resume();
		}
	}
}

void Engine::ClearStateStack(){
	while(!stateStack.empty()){
		stateStack.back()->Pause();
		stateStack.back()->Cleanup();
		stateStack.pop_back();
	}
}

CL_ResourceManager *Engine::GetResources(void){
	if(!resourceManagerExists){
		/**
		 *Initialization packed resources
		mFileSystem = CL_VirtualFileSystem("resources.zip", true);
		mResourceManager = CL_ResourceManager("resources.xml", mFileSystem.get_root_directory());
		***/
		resourceManager = CL_ResourceManager("resources.xml"); //Initialization unpacked resources
		resourceManagerExists = true;
	}
	return &resourceManager;
}

void Engine::Quit(void){
	ClearStateStack();
}

void Engine::QiteListener(const CL_InputEvent &event, const CL_InputState &state){
	if(event.id == CL_KEY_ESCAPE){
		quit = true;
	}
}