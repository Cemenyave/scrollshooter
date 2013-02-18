#include "precomp.h"
#include "GameObject.h"
#include "State.h"
#include <assert.h>

GameObject::GameObject(void){
	mSpawnState = false;
	mColor = CL_Colorf(255/255.0f, 234/255.0f, 117/255.0f);
	mZindex = 1;
	mWidth = 0;
	mHeight = 0;
	mCoordX = 0;
	mCoordY = 0;
}

GameObject::~GameObject(){}

bool GameObject::Spawn(float rCoordX, float rCoordY){
	mCoordX = rCoordX;
	mCoordY = rCoordY;
	mSpawnState = true;
	return true;
}

void GameObject::Draw(void){
	Engine &ObjEngine = Engine::GetEngine();
	if(!mSprite.is_null()){
		mSprite.update();
		mSprite.draw(ObjEngine.mGraphicContext, mCoordX, mCoordY);
	}else {
		CL_Draw::fill(ObjEngine.mGraphicContext, mCoordX, mCoordY, mCoordX + mWidth, mCoordY + mHeight, mColor);
	}
}

void GameObject::Update(void){
}

void GameObject::Destroy(void){
	mSpawnState = false;
}

