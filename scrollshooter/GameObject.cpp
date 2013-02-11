#include "precomp.h"
#include "GameObject.h"
#include "State.h"

/// <summary>
/// Initializes a new instance of the <see cref="GameObject"/> class.
/// </summary>
GameObject::GameObject(State *rState){
	mSpawnState = false;
	mColor = CL_Colorf(255/255.0f, 234/255.0f, 117/255.0f);
	rState->AddGameObject(this);
}

//GameObject::GameObject(int rWidth, int rHeight, CL_Color rColor = CL_Color::CL_Color(100, 100, 100)){
//	mWidth = rWidth;
//	mHeight = rHeight;
//	mColor = rColor;
//}

GameObject::~GameObject()
{
	
}


void GameObject::SetHeight(float rHeight)
{
	mHeight = rHeight;
}

float GameObject::GetHeight()
{
	return mHeight;
}

void GameObject::SetWidth(float rWidth)
{
	mWidth = rWidth;
}

float GameObject::GetWidth(void)
{
	return mWidth;
}

CL_Color GameObject::GetColor()
{
	return mColor;
}

bool GameObject::Spawn(float rCoordX, float rCoordY)
{
	mCoordX = rCoordX;
	mCoordY = rCoordY;
	mSpawnState = true;
	return true;
}

bool GameObject::IsSpawned()
{
	return mSpawnState;
}

void GameObject::Draw(Engine *rObjEngine)
{
	CL_Draw::box(rObjEngine->mGraphicContext, mCoordX, mCoordY, mCoordX + mWidth, mCoordY + mHeight, mColor);
}

void GameObject::Destroy(State *rState)
{
	mSpawnState = false;
}