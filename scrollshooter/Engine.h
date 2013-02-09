#pragma once

class State;

class Engine
{
	typedef std::shared_ptr<State> StatePtr;
	typedef std::vector<StatePtr> StateStack;
	
	int mFrameRate;
	int mLustUpdate;

	
	StateStack mStateStack;
		
	CL_DisplayWindow mWindow;
	CL_GraphicContext mGc;
	CL_Font mFont;
	CL_InputDevice mKeyboard;

	void Drow(void);
	void InputHandler(void);
	void Update(void);
public:
	bool mQuit;
	Engine(void);
	int Loop(void);
};