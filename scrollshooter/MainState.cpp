#include "precomp.h"
#include "MainState.h"
#include "Engine.h"
#include "GameObject.h"


MainState::MainState(void)
{
}

MainState::~MainState(void)
{
}

void MainState::Initialize(Engine *rObjEngine)
{
	mRectangle = new GameObject(this);
	mRectangle->SetHeight(100.0f);
	mRectangle->SetWidth(100.0f);
	mRectangle->Spawn(300.0f, 300.0f);
}

void MainState::Cleanup(Engine *rObjEngine)
{
	mRectangle->Destroy(this);
	State::Cleanup(rObjEngine);
}

void MainState::Update(void)
{
	
}