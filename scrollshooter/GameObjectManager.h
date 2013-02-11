#pragma once

class GameObject;

class GameObjectManager
{
	typedef std::shared_ptr<GameObject> GameObjectPtr;
	typedef std::vector<GameObjectPtr> GameObjectPool;

	GameObjectPool mGameObjectPool;
public:
	GameObjectManager(void);
	~GameObjectManager(void);

	void AddGameObject(GameObject *rGameObject);
	void RemoveGameObject(void);
	void ClearGameObjectPoll(void);

	void Update(void);
	void Drow(void);
};

