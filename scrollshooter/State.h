#pragma once
#include "Base.h"
#include "GameObject.h"
#include "GameObjectGroup.h"

class State:
	public Base
{
public:
	std::shared_ptr<GameObjectGroup> rootGroup;
	std::shared_ptr<GameObjectGroup> backgroundGroup;
	std::shared_ptr<GameObjectGroup> gameObjectGroup;
	std::shared_ptr<GameObjectGroup> uiGroup;

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
};