#pragma once
class DebugTool;
class State;

class Engine
{
	typedef std::shared_ptr<State> StatePtr;
	typedef std::vector<StatePtr> StateStack;
	int frameRate;
	int lustUpdate;
	bool resourceManagerExists;
	CL_VirtualFileSystem fileSystem;
	StateStack stateStack;

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
	int deltaTime;
	int windowWidth;
	int windowHeight;
	CL_GraphicContext graphicContext;
	CL_DisplayWindow window;
	CL_InputDevice keyboard;
	CL_InputDevice mouse;
	CL_ResourceManager resourceManager;
	std::shared_ptr<DebugTool> Debugger;

	static Engine &GetEngine(void);
	int Loop(void);
	void PushState(State *rNewState);
	void PopState(void);
	void ClearStateStack(void);
	CL_ResourceManager *GetResources(void);
};