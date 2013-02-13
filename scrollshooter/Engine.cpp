#include "precomp.h"
#include "State.h"
#include "GameObject.h"
#include "MainState.h"
#include "Engine.h"
#include <assert.h>
#include <ClanLib/application.h>

Engine::Engine(void){
	mQuit = false;

	CL_SetupCore setup_core;
	CL_SetupDisplay setup_display;
	CL_SetupGL setup_gl;

	mWindow = CL_DisplayWindow("Hello World", 640, 480);
 
	mGraphicContext = mWindow.get_gc();
	mKeyboard = mWindow.get_ic().get_keyboard();
	mMouse = mWindow.get_ic().get_mouse();
	
	mFrameRate = 60;	
	mLustUpdate = CL_System::get_time();
	
	mFileSystem = CL_VirtualFileSystem("resources.zip", true);
	mResourceManager = CL_ResourceManager("resources.xml", mFileSystem.get_root_directory());

	PushState(new MainState);
}

void Engine::Draw(void)
{
	mGraphicContext.clear();
	mStateStack.back()->Draw(this);
	mWindow.flip();
}

void Engine::InputHandler(void){
	if(mKeyboard.get_keycode(CL_KEY_ESCAPE)){
		mQuit = true;
	}
	return;
}

void Engine::Update(void){
	CL_KeepAlive::process();
	int curTime = CL_System::get_time();
	int deltaTime = curTime - mLustUpdate;
	if(deltaTime < 1000/mFrameRate)
	{
		return;
	}
	InputHandler();
	mStateStack.back()->Update(this);
	Draw();
	mLustUpdate = CL_System::get_time();
}

int Engine::Loop(void){
	try
	{
		while (!mQuit)
		{
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

void Engine::PushState(State *rNewState)
{
	assert(rNewState != nullptr);

	if(!mStateStack.empty()){
		mStateStack.back()->Pause();
	}

	mStateStack.push_back(StatePtr (rNewState));
	mStateStack.back()->Initialize(this);
}

void Engine::PopState()
{
	if(!mStateStack.empty())
	{
		mStateStack.back()->Pause();
		mStateStack.back()->Cleanup(this);
		mStateStack.pop_back();

		if(!mStateStack.empty())
		{
			mStateStack.back()->Resume();
		}
	}
}

void Engine::ClearStateStack()
{
	while(!mStateStack.empty())
	{
		mStateStack.back()->Pause();
		mStateStack.back()->Cleanup(this);
		mStateStack.pop_back();
	}
}

void Engine::Quit(void)
{
	ClearStateStack();
}