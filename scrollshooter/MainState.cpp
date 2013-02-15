#include "precomp.h"
#include "MainState.h"
#include "Engine.h"
#include "GameObject.h"




MainState::MainState(void){
}

MainState::~MainState(void)
{
}

void MainState::Initialize(Engine *rObjEngine)
{
	mTest1Button = GameObjectFactory<ObjectButton>(GAMEOBJECT);
	mTest1Button->mHeight = 50.0f;
	mTest1Button->mWidth = 50.0f;
	mTest1Button->Spawn(150.0f, 150.0f);

	mRectangle = GameObjectFactory<GameObject>(GAMEOBJECT);
	mRectangle->mSprite = CL_Sprite(rObjEngine->mGraphicContext, "Boat", rObjEngine->GetResources());
	mRectangle->mHeight = 100.0f;
	mRectangle->mWidth = 100.0f;
	mRectangle->Spawn(200.0f, 200.0f);
}

void MainState::Cleanup(Engine *rObjEngine)
{
//	mTest1Button->Destroy(this);
//	mRectangle->Destroy(this);
	State::Cleanup(rObjEngine);
}

void MainState::Update(Engine *rObjEngine){
	//что делать если объект не создан?
	State::Update(rObjEngine);
	if(mTest1Button->mOnClick){
		Test1ClickHandler();
	}
}

void MainState::Test1ClickHandler(){
	mRectangle->mCoordX += 3.0f;
	mRectangle->mCoordY += 3.0f;
}
