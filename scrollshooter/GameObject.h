#pragma once
#include "Engine.h"

class GameObject
{
public:
	GameObject(State * const rState = nullptr);
	virtual ~GameObject(void);

	float mWidth;
	float mHeight;
	float mCoordX;
	float mCoordY;
	bool mSpawnState;
	CL_Colorf mColor;
	CL_Sprite mSprite;

	virtual bool Spawn(const float rCoordX, const float rCoordY);
	virtual void Draw(Engine *rObjEngine);
	virtual void Destroy(State *rState);
	virtual void Update(Engine *rObjEngine);
};