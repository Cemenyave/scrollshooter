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

	Engine(void);
	~Engine(void);
	Engine(Engine const&);
	void operator=(Engine const&);
	void Draw(void);
	void Update(void);
	const float CountFps(void);
	void QiteListener(const CL_InputEvent &event, const CL_InputState &state);
	void Quit(void);
public:
	static Engine Instance;
	bool mQuit;
	int fps;
	int mDeltaTime;
	int mWindowWidth;
	int mWindowHeight;
	CL_GraphicContext mGraphicContext;
	CL_DisplayWindow mWindow;
	CL_InputDevice mKeyboard;
	CL_InputDevice mMouse;
	CL_ResourceManager mResourceManager;
	std::shared_ptr<DebugTool> Debugger;
	CL_SlotContainer mSlotInput;

	static Engine &GetEngine(void);
	int Loop(void);
	void PushState(State *rNewState);
	void PopState(void);
	void ClearStateStack(void);
	CL_ResourceManager *GetResources(void);
};