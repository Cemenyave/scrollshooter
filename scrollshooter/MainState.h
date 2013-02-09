#pragma once
#include "state.h"
class MainState :
	public State
{
	CL_Font mFont;
public:
	MainState(void);
	virtual ~MainState(void);

	void Initialize(Engine *rObjEngine);
	void Cleanup(void);
	void Drow(void);
};

