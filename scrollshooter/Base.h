#pragma once
#include "Engine.h"
class Base
{
public:
	int mDeltaTime;
	CL_GraphicContext &mGraphicContext;
	CL_InputDevice &mKeyboard;
	CL_InputDevice &mMouse;
	CL_SlotContainer &mSlotInput;

	Base(void);
	virtual ~Base(void);
	virtual void Update(void);
};

