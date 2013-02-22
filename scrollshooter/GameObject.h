#pragma once
#include "GameComponent.h"

class GameObject:
	public GameComponent
{
public:
	GameObject(void);
	virtual ~GameObject(void);

	float width;
	float height;
	float coordX;
	float coordY;
	int zIndex;
	bool spawnState;
	CL_Colorf color;
	CL_Sprite sprite;

	virtual bool Spawn(const float rCoordX, const float rCoordY);
	virtual void Draw(void);
	virtual void Destroy(void);
	//dose not work with rotating object
	virtual float const GetCentrePointX(void);
	//dose not work with rotating object
	virtual float const GetCentrePointY(void);
};