#pragma once
#include "Engine.h"
class Base
{
public:
	int &deltaTime;
	CL_GraphicContext &graphicContext;
	CL_InputDevice &keyboard;
	CL_InputDevice &mouse;
	CL_ResourceManager *resources;

	Base(void);
	virtual ~Base(void);
	virtual void Update(void);
	virtual void Draw(void);
};

