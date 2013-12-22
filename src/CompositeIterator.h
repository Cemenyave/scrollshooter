#pragma once
#include "Iterator.h"
#include "GameComponent.h"

class CompositeIterator:
	public Iterator
{
public:
	//type definitions
	typedef std::shared_ptr<std::vector<std::shared_ptr<GameComponent>>> collection;
	typedef std::vector<std::shared_ptr<GameComponent>>::iterator collectionIter;

	//members
	std::vector<Iterator*> stack;
	collectionIter currentIter;
	collectionIter lastElement;

	//methods
	CompositeIterator(std::vector<gameComponentPtr> *elementsVector);
	~CompositeIterator(void);

	std::shared_ptr<GameComponent> Next(void);
	bool HasNext(void);
};