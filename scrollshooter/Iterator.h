#pragma once
#include "GameComponent.h"

//Base class for GameComponents Iterator
class Iterator
{
public:
	std::vector<std::shared_ptr<GameComponent>> collection;

	Iterator(void);
	virtual ~Iterator(void);

	virtual std::shared_ptr<GameComponent> Next(void);
	virtual bool HasNext(void);
	virtual void Remove(void);
};