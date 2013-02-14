#pragma once
#include "Engine.h"
#include "GameObject.h"

class State
{
	typedef std::shared_ptr<GameObject> GameObjectPtr;
	typedef std::vector<GameObjectPtr> GameObjectsVector;

	GameObjectsVector mGameObjects;
	GameObjectsVector mBackgroundObjects;
	GameObjectsVector mEffectObjects;
	GameObjectsVector::iterator mGameObjectIter;
protected:
	void GameObjectIteration(GameObjectsVector &Set, const int rAction, Engine *rObjEngine);
	void const InsertByZindex(GameObject * const rGameObject, GameObjectsVector &Set);
public:
	State(void);
	virtual ~State(void);

	enum {BACKGROUND, GAMEOBJECT, EFFECT};
	enum {UPDATE, DRAW};

	virtual void Initialize(Engine *rObjEngine);
	virtual void Cleanup(Engine *rObjEngine);
	virtual void Pause(void);
	virtual void Resume(void);
	virtual void Update(Engine *rObjEngine);
	virtual void Draw(Engine *rObjEngine);

	void AddGameObject(GameObject *rGameObject, const int rType);
	void RemoveGameObject(GameObject *rGameObject);
	void RemoveAllGameObjects();
	void ClearGameObjectsVector(GameObjectsVector &Set);
};