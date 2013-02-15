#pragma once
#include "GameObject.h"
#include "Engine.h"

class ObjectButton :
	public GameObject
{
public:
	ObjectButton();
	~ObjectButton(void);
	bool mOnHover;
	bool mOnClick;
	virtual void HoverEventHandler(Engine *rOgjEngine);
	virtual void ClickEventHandler(Engine *rOgjEngine);
	void Update(Engine *rObjEngine);
};