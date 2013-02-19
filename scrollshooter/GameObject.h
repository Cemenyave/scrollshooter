#pragma once
#include "Base.h"

class GameObject:
	public Base
{
public:
	GameObject(void);
	virtual ~GameObject(void);

	float mWidth;
	float mHeight;
	float mCoordX;
	float mCoordY;
	int mZindex;
	bool mSpawnState;
	CL_Colorf mColor;
	CL_Sprite mSprite;

	virtual bool Spawn(const float rCoordX, const float rCoordY);
	virtual void Draw(void);
	virtual void Destroy(void);
};