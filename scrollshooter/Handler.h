#pragma once
#include"Engine.h"
class Handler
{
public:
	Handler(void);
	~Handler(void);

	virtual void Handl(Engine *rObjEngine);
};

