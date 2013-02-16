#include "precomp.h"
#include "MainState.h"
#include "Engine.h"
#include "GameObject.h"
#include "DebugTool.h"

MainState::MainState(void){}

MainState::~MainState(void){}

void MainState::Initialize(Engine *rObjEngine){
	mFillBackGround = GameObjectFactory<GameObject>(BACKGROUND);
	mFillBackGround->mWidth = rObjEngine->mWindowWidth;
	mFillBackGround->mHeight = rObjEngine->mWindowHeight;
	mFillBackGround->mColor = CL_Colorf::black;
	mFillBackGround->Spawn(0, 0);

	for(int i = 0; i < 10; i++){
		mStars.push_back(GameObjectFactory<GameObject>(BACKGROUND));
		mStars.back()->mZindex = 2;
		mStars.back()->mWidth = 10.0f;
		mStars.back()->mHeight = 10.0f;
		mStars.back()->Spawn(rand() % (rObjEngine->mWindowWidth - 40) + 20, rand() % (rObjEngine->mWindowHeight - 40) + 20);
	}

	mTest1Button = GameObjectFactory<ObjectButton>(GAMEOBJECT);
	mTest1Button->mHeight = 50.0f;
	mTest1Button->mWidth = 50.0f;
	mTest1Button->Spawn(150.0f, 150.0f);

	mRectangle = GameObjectFactory<GameObject>(GAMEOBJECT);
	mRectangle->mSprite = CL_Sprite(rObjEngine->mGraphicContext, "Boat", rObjEngine->GetResources());
	mRectangle->mHeight = 100.0f;
	mRectangle->mWidth = 100.0f;
	mRectangle->Spawn(50.0f, 250.0f);
}

void MainState::Cleanup(Engine *rObjEngine){
	State::Cleanup(rObjEngine);
}

void MainState::Update(Engine *rObjEngine){
	State::Update(rObjEngine);
	if(mTest1Button->mOnClick){
		Test1ClickHandler();
	}
}

void MainState::Test1ClickHandler(){
	mRectangle->mCoordX += 3.0f;
	mRectangle->mCoordY += 3.0f;
}
