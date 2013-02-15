#pragma once
#include "state.h"
#include "GameObject.h"
#include "ObjectButton.h"

class MainState :
	public State
{
protected:
	typedef std::shared_ptr<GameObject> GameObjectPtr;

	GameObjectPtr mRectangle;
	std::shared_ptr<ObjectButton> mTest1Button;
public:
	MainState(void);
	~MainState(void);

	void Initialize(Engine *rObjEngine);
	void Cleanup(Engine *rObjEngine);
	void Update(Engine *rObjEngine);
	void Test1ClickHandler(void);
};

