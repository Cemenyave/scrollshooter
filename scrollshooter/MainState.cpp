#include "precomp.h"
#include "MainState.h"
#include "Engine.h"
#include "GameObject.h"
#include "ClickTest1ButtonHandler.h"


MainState::MainState(void)
{
}

MainState::~MainState(void)
{
}

void MainState::Initialize(Engine *rObjEngine)
{
	mTest1Button = new ObjectButton(this);
	AddGameObject(mTest1Button, GAMEOBJECT);
	mTest1Button->mHeight = 50.0f;
	mTest1Button->mWidth = 50.0f;
	mTest1Button->Spawn(150.0f, 150.0f);

	mRectangle = new GameObject(this);
	AddGameObject(mRectangle, GAMEOBJECT);
	mRectangle->mSprite = CL_Sprite(rObjEngine->mGraphicContext, "Boat", rObjEngine->GetResources());
	mRectangle->mHeight = 100.0f;
	mRectangle->mWidth = 100.0f;
	mRectangle->Spawn(300.0f, 300.0f);
}

void MainState::Cleanup(Engine *rObjEngine)
{
	mTest1Button->Destroy(this);
	mRectangle->Destroy(this);
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