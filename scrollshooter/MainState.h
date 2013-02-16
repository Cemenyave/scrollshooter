#pragma once
#include "state.h"
#include "GameObject.h"
#include "ObjectButton.h"

class MainState :
	public State
{
protected:
	std::shared_ptr<GameObject> mRectangle;
	std::shared_ptr<ObjectButton> mTest1Button;
	std::shared_ptr<GameObject> mFillBackGround;
	std::vector<std::shared_ptr<GameObject>> mStars;
public:
	MainState(void);
	~MainState(void);

	void Initialize(Engine *rObjEngine);
	void Cleanup(Engine *rObjEngine);
	void Update(Engine *rObjEngine);
	void Test1ClickHandler(void);
};

