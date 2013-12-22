#pragma once
#include "GameComponent.h"
#include "NullIterator.h"
#include "Iterator.h"

class GameObject:
	public GameComponent
{
public:
	float width;
	float height;
	float coordX;
	float coordY;
	int zIndex;
	bool spawnState;
	CL_Colorf color;
	CL_Sprite sprite;
	NullIterator myIteretor;

	GameObject(void);
	virtual ~GameObject(void);

	Iterator *CreateIterator(void);
	virtual bool Spawn(const float rCoordX, const float rCoordY);
	virtual void Draw(void);
	virtual void Destroy(void);
	//dose not work with rotating object
	virtual float const GetCentrePointX(void);
	//dose not work with rotating object
	virtual float const GetCentrePointY(void);
};