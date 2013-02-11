#pragma once
#include "state.h"
#include "GameObject.h"
class MainState :
	public State
{
protected:
	GameObject *mRectangle;
public:
	MainState(void);
	~MainState(void);

	void Initialize(Engine *rObjEngine);
	void Cleanup(Engine *rObjEngine);
	void Update(void);
};

