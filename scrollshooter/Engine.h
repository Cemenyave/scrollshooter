#pragma once

class State;

class Engine
{
	typedef std::shared_ptr<State> StatePtr;
	typedef std::vector<StatePtr> StateStack;
	
	int mFrameRate;
	int mLustUpdate;

	StateStack mStateStack;

	void Draw(void);
	void InputHandler(void);
	void Update(void);
	CL_VirtualFileSystem mFileSystem;

	bool mResourceManagerExists;
	const float CountFps(void);
public:
	bool mQuit;
	int mWindowWidth;
	int mWindowHeight;

	CL_GraphicContext mGraphicContext;
	CL_DisplayWindow mWindow;
	CL_InputDevice mKeyboard;
	CL_InputDevice mMouse;
	CL_ResourceManager mResourceManager;

	Engine(void);
	int Loop(void);

	void PushState(State *rNewState);
	void PopState(void);
	void ClearStateStack(void);
	CL_ResourceManager *GetResources(void);

	void Quit(void);
};