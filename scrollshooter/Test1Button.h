#pragma once
#include "objectbutton.h"
#include "State.h"
class Test1Button :
	public ObjectButton
{
public:
	Test1Button(State * const rState = nullptr);
	~Test1Button(void);
	void ClickEventHandler(Engine *rOgjEngine);
};

