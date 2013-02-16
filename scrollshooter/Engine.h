#pragma once
class DebugTool;
class State;

class Engine
{
	typedef std::shared_ptr<State> StatePtr;
	typedef std::vector<StatePtr> StateStack;
	int mFrameRate;
	int mLustUpdate;
	bool mResourceManagerExists;
	CL_VirtualFileSystem mFileSystem;
	StateStack mStateStack;

	void Draw(void);
	void Update(void);
	const float CountFps(void);
	void QiteListener(const CL_InputEvent &event, const CL_InputState &state);
	void Quit(void);
public:
	bool mQuit;
	int fps;
	int mWindowWidth;
	int mWindowHeight;
	CL_GraphicContext mGraphicContext;
	CL_DisplayWindow mWindow;
	CL_InputDevice mKeyboard;
	CL_InputDevice mMouse;
	CL_ResourceManager mResourceManager;
	std::shared_ptr<DebugTool> Debugger;
	CL_SlotContainer slot_key_down;

	Engine(void);
	~Engine(void);
	int Loop(void);
	void PushState(State *rNewState);
	void PopState(void);
	void ClearStateStack(void);
	CL_ResourceManager *GetResources(void);
};