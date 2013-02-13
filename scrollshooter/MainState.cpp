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
	AddGameObject(mTest1Button);
	//mTest1Button->SetClickHandler(rObjEngine->mHandlerManager.AddHandler(new ClickTest1ButtonHandler()));
	mTest1Button->mHeight = 50.0f;
	mTest1Button->mWidth = 50.0f;
	mTest1Button->Spawn(150.0f, 150.0f);

	mRectangle = new GameObject(this);
	AddGameObject(mRectangle);
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

void MainState::Update(void)
{
	
}