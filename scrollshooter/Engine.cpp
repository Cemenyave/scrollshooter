#include "precomp.h"
#include "State.h"
#include "GameObject.h"
#include "MainMenu.h"
#include "Engine.h"
#include "DebugTool.h"
#include <assert.h>
#include <ClanLib/application.h>

Engine::Engine(void){
	mQuit = false;
	fps = 0;
	mResourceManagerExists = false;
	mWindowWidth = 800;
	mWindowHeight = 600;

	CL_SetupCore setup_core;
	CL_SetupDisplay setup_display;
	CL_SetupGL setup_gl;

	mWindow = CL_DisplayWindow("Hello World", mWindowWidth, mWindowHeight);
	mGraphicContext = mWindow.get_gc();
	mKeyboard = mWindow.get_ic().get_keyboard();
	mMouse = mWindow.get_ic().get_mouse();
	mFrameRate = 60;	
	mLustUpdate = CL_System::get_time();
	mSlotInput.connect(mKeyboard.sig_key_down(), this, &Engine::QiteListener);
	Debugger = std::shared_ptr<DebugTool>(new DebugTool);
	PushState(new MainMenu);
}

Engine::~Engine(){}

Engine &Engine::GetEngine(){
	static Engine Instance;
	return Instance;
}

void Engine::Draw(void){
	mGraphicContext.clear();
	mStateStack.back()->Draw();
	Debugger->Draw();
	mWindow.flip();
}

void Engine::Update(void){
	CL_KeepAlive::process();
	fps = (int)CountFps();
	if(fps > mFrameRate)
	{
		return;
	}
	mStateStack.back()->Update();
	Draw();
	mLustUpdate = CL_System::get_time();
	Debugger->Update();
}

int Engine::Loop(void){
	try
	{
		while (!mQuit){
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
	mDeltaTime = curTime - mLustUpdate;
	if(mDeltaTime < 1){
		return 1000.0f;
	}
	return 1000.0f/mDeltaTime;
}

void Engine::PushState(State *rNewState)
{
	assert(rNewState != nullptr);

	if(!mStateStack.empty()){
		mStateStack.back()->Pause();
	}

	mStateStack.push_back(StatePtr (rNewState));
	mStateStack.back()->Initialize();
}

void Engine::PopState(){
	if(!mStateStack.empty()){
		mStateStack.back()->Pause();
		mStateStack.back()->Cleanup();
		mStateStack.pop_back();

		if(!mStateStack.empty()){
			mStateStack.back()->Resume();
		}
	}
}

void Engine::ClearStateStack(){
	while(!mStateStack.empty()){
		mStateStack.back()->Pause();
		mStateStack.back()->Cleanup();
		mStateStack.pop_back();
	}
}

CL_ResourceManager *Engine::GetResources(void){
	if(!mResourceManagerExists){
		/**
		 *Initialization packed resources
		mFileSystem = CL_VirtualFileSystem("resources.zip", true);
		mResourceManager = CL_ResourceManager("resources.xml", mFileSystem.get_root_directory());
		***/
		mResourceManager = CL_ResourceManager("resources.xml"); //Initialization unpacked resources
		mResourceManagerExists = true;
	}
	return &mResourceManager;
}

void Engine::Quit(void){
	ClearStateStack();
}

void Engine::QiteListener(const CL_InputEvent &event, const CL_InputState &state){
	if(event.id == CL_KEY_ESCAPE){
		mQuit = true;
	}
}