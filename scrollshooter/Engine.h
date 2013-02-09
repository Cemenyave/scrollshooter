#pragma once

class State;

class Engine
{
	typedef std::shared_ptr<State> StatePtr;
	typedef std::vector<StatePtr> StateStack;
	
	int mFrameRate;
	int mLustUpdate;

	
	StateStack mStateStack;
	
	void Drow(void);
	void InputHandler(void);
	void Update(void);

public:
	bool mQuit;
	
	CL_GraphicContext mGraphicContext;
	CL_DisplayWindow mWindow;
	CL_InputDevice mKeyboard;

	Engine(void);
	int Loop(void);

	void PushState(State *rNewState);
	void PopState(void);
	void ClearStateStack(void);
};