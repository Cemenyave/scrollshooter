#pragma once
#include "base.h"
#include "CompositeIterator.h"
class GameComponent :
	public Base
{
public:
	//type definitions
	typedef std::shared_ptr<GameComponent> gameComponentPtr;

	//members
	int priority;

	//methods
	GameComponent(void);
	~GameComponent(void);

	virtual void Add(std::shared_ptr<GameComponent> newItem);
	virtual void Remove(std::shared_ptr<GameComponent> elemForErase);
	virtual void GetChild(void);
	virtual bool HasChild(void);
	virtual Iterator *CreateIterator();
};

