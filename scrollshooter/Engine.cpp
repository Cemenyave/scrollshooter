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
	

	mFrameRate = 60;	
	mLustUpdate = CL_System::get_time();

	mStateStack.push_back(StatePtr(new MainState));
}

void Engine::Drow(void){
	mGraphicContext.clear(CL_Colorf::cadetblue);
 
	CL_Draw::line(mGraphicContext, 0, 110, 640, 110, CL_Colorf::yellow);
	mFont.draw_text(mGraphicContext, 100, 100, "Hello World!", CL_Colorf::lightseagreen);

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
	Drow();
	mLustUpdate = CL_System::get_time();
}

int Engine::Loop(void){
	try
	{
		while (!mQuit)
		{
			Update();
		}
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
		mStateStack.back()->Cleanup();
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
		mStateStack.back()->Cleanup();
		mStateStack.pop_back();
	}
}