#pragma once
#include "gameobject.h"
#include "Engine.h"
#include "Handler.h"

class ObjectButton :
	public GameObject
{
	Handler *mClickHandler;
	Handler *mHoverHandler;
public:
	ObjectButton(State * const  rState);
	~ObjectButton(void);
	bool mHovered;
	virtual void HoverEventHandler(Engine *rOgjEngine);
	virtual void ClickEventHandler(Engine *rOgjEngine);
	//void SetHoverHandler(Handler *rObjHandler);
	//void SetClickHandler(Handler *rObjHandler);
};