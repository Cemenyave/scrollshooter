#include "precomp.h"
#include "GameObject.h"
#include "State.h"
#include <assert.h>

GameObject::GameObject(State * const rState){
	assert(rState != nullptr);
	mSpawnState = false;
	mColor = CL_Colorf(255/255.0f, 234/255.0f, 117/255.0f);
}

GameObject::~GameObject(){}

bool GameObject::Spawn(float rCoordX, float rCoordY){
	mCoordX = rCoordX;
	mCoordY = rCoordY;
	mSpawnState = true;
	return true;
}

void GameObject::Draw(Engine *rObjEngine){
	CL_Draw::box(rObjEngine->mGraphicContext, mCoordX, mCoordY, mCoordX + mWidth, mCoordY + mHeight, mColor);
}

void GameObject::Destroy(State *rState){
	mSpawnState = false;
}