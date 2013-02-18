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
	GameObjectPtr mBuffer; //buffer for passive sorting
protected:
	void GameObjectIteration(GameObjectsVector &Set, const int rAction);
	void const InsertByZindex(GameObjectPtr const rGameObject, GameObjectsVector &Set);
public:
	State(void);
	virtual ~State(void);

	enum {BACKGROUND, GAMEOBJECT, EFFECT};
	enum {UPDATE, DRAW};

	virtual void Initialize(void);
	virtual void Cleanup(void);
	virtual void Pause(void);
	virtual void Resume(void);
	virtual void Update(void);
	virtual void Draw(void);

	template <class _Type> std::shared_ptr<_Type> GameObjectFactory(const int rType){
		std::shared_ptr<_Type> temp = std::shared_ptr<_Type>(new _Type);
		AddGameObject(temp, rType);
		return temp;
	};
	
	void AddGameObject(GameObjectPtr rGameObject, const int rType);
	void RemoveGameObject(GameObject *rGameObject);
	void RemoveAllGameObjects();
	void ClearGameObjectsVector(GameObjectsVector &Set);
};