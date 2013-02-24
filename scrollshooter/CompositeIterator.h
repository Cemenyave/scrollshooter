#pragma once
#include "GameComponent.h"
#include "Iterator.h"

class CompositeIterator: 
	public Iterator
{
public:
	//type definitions
	typedef std::vector<std::shared_ptr<GameComponent>>::iterator gameIterator;
	
	//members
	std::vector<gameIterator> stack;   

	//methods
	CompositeIterator(std::vector<gameComponentPtr> *collection);
	~CompositeIterator(void);

	gameComponentPtr Next(void);
	bool HasNext(void);
	void Remvoe(void);
};

