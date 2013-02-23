#pragma once
#include "base.h"
#include "Iterator.h"
class GameComponent :
	public Base
{
public:
	int priority;
	std::shared_ptr<GameComponent> parent;

	GameComponent(void);
	~GameComponent(void);

	virtual void Add(std::shared_ptr<GameComponent> newItem);;
	virtual void Remove(std::shared_ptr<GameComponent> elemForErase);;
	virtual void GetChild(void);
	virtual bool HasChild(void);
	virtual Iterator CreateIterator();
	void Update(void);
	void Draw(void);
};

