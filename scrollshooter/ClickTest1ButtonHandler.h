#pragma once
#include "handler.h"
#include "State.h"
class ClickTest1ButtonHandler :
	public Handler
{
public:
	ClickTest1ButtonHandler(void);
	~ClickTest1ButtonHandler(void);
	void Handle(GameObject *rObjGameObject, State *rState);
};

