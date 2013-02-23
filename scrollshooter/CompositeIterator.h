#pragma once
#include "GameComponent.h"

class CompositeIterator
{
public:
	//type definitions
	typedef std::vector<std::shared_ptr<GameComponent>>::iterator gameIterator;
	
	//members
	std::vector<gameIterator> stack;   

	//methods
	CompositeIterator(gameIterator topLevelIterator);
	~CompositeIterator(void);

	void Next(void);

};

