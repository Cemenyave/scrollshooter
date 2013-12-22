#pragma once
#include "state.h"
#include "GameObject.h"
#include "NewGameButton.h"
#include "ControlsButton.h"
#include "CreditsButton.h"
#include "QuitButton.h"

class MainMenu :
	public State
{
protected:
	//type definitions
	enum{NEWGAMEBUTTON, CONTROLSBUTTON, CREDITSBUTTON, QUITBUTTON};

	//members
	std::shared_ptr<NewGameButton> mNewGameButton;
	std::shared_ptr<ControlsButton> mControlsButton;
	std::shared_ptr<CreditsButton> mCreditsButton;
	std::shared_ptr<QuitButton> mQuitButton;
	std::shared_ptr<GameObject> mFillBackGround;
	std::vector<std::shared_ptr<GameObject>> mStars;
	int mCursor;
	CL_Slot menuControl;

	//methods
	void GenerateBackground(void);
	void GenerateMenu(void);
public:
	//methods
	MainMenu(void);
	~MainMenu(void);

	void Initialize(void);
	void Pause(void);
	void Resume(void);
	void Cleanup(void);
	void NewGameHandler(CL_InputEvent const &event, CL_InputState const &state);
	void ControlsHandler(CL_InputEvent const &event, CL_InputState const &state);
	void CreditsHandler(CL_InputEvent const &event, CL_InputState const &state);
	void QuitHandler(CL_InputEvent const &event, CL_InputState const &state);
	void NavigationHandler(CL_InputEvent const &event, CL_InputState const &state);
};

