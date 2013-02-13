#pragma once
#include "Engine.h"
#include "GameObject.h"

class State
{
	typedef std::shared_ptr<GameObject> GameObjectPtr;
	typedef std::vector<GameObjectPtr> GameObjectsVector;

	GameObjectsVector mGameObjects;
	GameObjectsVector::iterator mGameObjectIter;
public:
	State(void);
	virtual ~State(void);

	virtual void Initialize(Engine *rObjEngine);
	virtual void Cleanup(Engine *rObjEngine);
	virtual void Pause(void);
	virtual void Resume(void);
	virtual void Update(Engine *rObjEngine);
	virtual void Draw(Engine *rObjEngine);

	
	void AddGameObject(GameObject *rGameObject);
	void RemoveGameObject(GameObject *rGameObject);
	void RemoveAllGameObjects();
};