#include "precomp.h"
#include "MainMenu.h"
#include "Engine.h"
#include "GameObject.h"
#include "Star.h"
#include "Level.h"
#include "DebugTool.h"

MainMenu::MainMenu(void):
	mNewGameButton(new NewGameButton),
	mControlsButton(new ControlsButton),
	mCreditsButton(new CreditsButton),
	mQuitButton(new QuitButton),
	mFillBackGround(new GameObject),
	mStars(),
	mCursor(0),
	menuControl()
{
	
}

MainMenu::~MainMenu(void){}

void MainMenu::Initialize(){
	State::Initialize();
	GenerateBackground();
	GenerateMenu();
}

void MainMenu::Pause(void){
	State::Pause();
	menuControl.disable();
	mNewGameButton->Disable();
	mControlsButton->Disable();
	mCreditsButton->Disable();
	mQuitButton->Disable();
}

void MainMenu::Resume(void){
	State::Resume();
	menuControl.enable();
	mNewGameButton->Enable();
	mControlsButton->Enable();
	mCreditsButton->Enable();
	mQuitButton->Enable();
}

void MainMenu::Cleanup(void){
	State::Cleanup();
}

void MainMenu::GenerateBackground(void){
	Engine &ObjEngine = Engine::GetEngine();
	mFillBackGround->priority = 1;
	mFillBackGround->width = (float)ObjEngine.windowWidth;
	mFillBackGround->height = (float)ObjEngine.windowHeight;
	mFillBackGround->color = CL_Colorf::black;
	backgroundGroup->Add(mFillBackGround);
	mFillBackGround->Spawn(0, 0);

	for(int i = 0; i < 30; i++){
		std::shared_ptr<Star> star = std::shared_ptr<Star>(new Star);
		star->priority = 2;
		backgroundGroup->Add(star);
		mStars.push_back(std::shared_ptr<Star>(new Star));
		mStars.back()->Spawn((float)(rand() % (ObjEngine.windowWidth - 40) + 20), (float)(rand() % (ObjEngine.windowHeight - 40) + 20));
	}
}

void MainMenu::GenerateMenu(void){
	mCursor = NEWGAMEBUTTON;
	menuControl = keyboard.sig_key_down().connect(this, &MainMenu::NavigationHandler);
	menuControl.enable();

	uiGroup->Add(mNewGameButton);
	mNewGameButton->Spawn(220.0f, 150.0f);
	mNewGameButton->SetHandler(this, &MainMenu::NewGameHandler);
	mNewGameButton->Hover();

	uiGroup->Add(mControlsButton);
	mControlsButton->Spawn(220.0f, 200.0f);
	mControlsButton->SetHandler(this, &MainMenu::ControlsHandler);

	uiGroup->Add(mCreditsButton);;
	mCreditsButton->Spawn(220.0f, 250.0f);
	mCreditsButton->SetHandler(this, &MainMenu::CreditsHandler);

	uiGroup->Add(mQuitButton);
	mQuitButton->Spawn(220.0f, 300.0f);
	mQuitButton->SetHandler(this, &MainMenu::QuitHandler);
}

void MainMenu::NewGameHandler(CL_InputEvent const &event, CL_InputState const &state){
	if(mNewGameButton->mOnHover){
		if(event.id ==  CL_KEY_ENTER){
			Engine &ObjEngine = Engine::GetEngine();
			ObjEngine.Debugger->Log("New Game");
			ObjEngine.PushState(new Level);
			//ObjEngine.PushState();
		}
	}
}

void MainMenu::ControlsHandler(CL_InputEvent const &event, CL_InputState const &state){
	if(mControlsButton->mOnHover){
		if(event.id ==  CL_KEY_ENTER){
			Engine &ObjEngine = Engine::GetEngine();
			ObjEngine.Debugger->Log("Controls");
			//ObjEngine.PushState();
		}
	}
}

void MainMenu::CreditsHandler(CL_InputEvent const &event, CL_InputState const &state){
	if(mCreditsButton->mOnHover){
		if(event.id ==  CL_KEY_ENTER){
			Engine &ObjEngine = Engine::GetEngine();
			ObjEngine.Debugger->Log("Credits");
			//ObjEngine.PushState();
		}
	}
}

void MainMenu::QuitHandler(CL_InputEvent const &event, CL_InputState const &state){
	if(mQuitButton->mOnHover){
		if(event.id ==  CL_KEY_ENTER){
			Engine &ObjEngine = Engine::GetEngine();
			ObjEngine.Debugger->Log("Quit");
			//ObjEngine.PushState();
		}
	}
}

void MainMenu::NavigationHandler(CL_InputEvent const &event, CL_InputState const &state){;
	if(event.id == CL_KEY_S || event.id ==  CL_KEY_DOWN){
		Engine &ObjEngine = Engine::GetEngine();
		ObjEngine.Debugger->Log("Key Down Pressed");
		switch (mCursor){
		case NEWGAMEBUTTON:
			mNewGameButton->Hover();
			mControlsButton->Hover();
			mCursor++;
			break;
		case CONTROLSBUTTON:
			mControlsButton->Hover();
			mCreditsButton->Hover();
			mCursor++;
			break;
		case CREDITSBUTTON:
			mCreditsButton->Hover();
			mQuitButton->Hover();
			mCursor++;
			break;
		case QUITBUTTON:
			break;
		default:
			break;
		}
	}if(event.id == CL_KEY_W || event.id ==  CL_KEY_UP){
		Engine &ObjEngine = Engine::GetEngine();
		ObjEngine.Debugger->Log("Key Up Pressed");
		switch (mCursor){
		case NEWGAMEBUTTON:
			break;
		case CONTROLSBUTTON:
			mControlsButton->Hover();
			mNewGameButton->Hover();
			mCursor--;
			break;
		case CREDITSBUTTON:
			mCreditsButton->Hover();
			mControlsButton->Hover();
			mCursor--;
			break;
		case QUITBUTTON:
			mQuitButton->Hover();
			mCreditsButton->Hover();
			mCursor--;
			break;
		}
	}
}