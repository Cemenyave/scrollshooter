#include "precomp.h"
#include "MainMenu.h"
#include "Engine.h"
#include "GameObject.h"
#include "Star.h"
#include "Level.h"
#include "DebugTool.h"

MainMenu::MainMenu(void){
	
}

MainMenu::~MainMenu(void){}

void MainMenu::Initialize(){
	GenerateBackground();
	GenerateMenu();
}

void MainMenu::Pause(void){
	menuControl.disable();
}

void MainMenu::Cleanup(void){
	State::Cleanup();
}

void MainMenu::GenerateBackground(void){
	Engine &ObjEngine = Engine::GetEngine();
	mFillBackGround = GameObjectFactory<GameObject>(BACKGROUND);
	mFillBackGround->width = (float)ObjEngine.windowWidth;
	mFillBackGround->height = (float)ObjEngine.windowHeight;
	mFillBackGround->color = CL_Colorf::black;
	mFillBackGround->Spawn(0, 0);

	for(int i = 0; i < 30; i++){
		mStars.push_back(GameObjectFactory<Star>(BACKGROUND));
		mStars.back()->Spawn((float)(rand() % (ObjEngine.windowWidth - 40) + 20), (float)(rand() % (ObjEngine.windowHeight - 40) + 20));
	}
}

void MainMenu::GenerateMenu(void){
	mCursor = NEWGAMEBUTTON;
	menuControl = keyboard.sig_key_down().connect(this, &MainMenu::NavigationHandler);
	menuControl.enable();

	mNewGameButton = GameObjectFactory<NewGameButton>(GAMEOBJECT);
	mNewGameButton->Spawn(220.0f, 150.0f);
	mNewGameButton->SetHandler(this, &MainMenu::NewGameHandler);
	mNewGameButton->Hover();

	mControlsButton = GameObjectFactory<ControlsButton>(GAMEOBJECT);
	mControlsButton->Spawn(220.0f, 200.0f);
	mControlsButton->SetHandler(this, &MainMenu::ControlsHandler);

	mCreditsButton = GameObjectFactory<CreditsButton>(GAMEOBJECT);
	mCreditsButton->Spawn(220.0f, 250.0f);
	mCreditsButton->SetHandler(this, &MainMenu::CreditsHandler);

	mQuitButton = GameObjectFactory<QuitButton>(GAMEOBJECT);
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