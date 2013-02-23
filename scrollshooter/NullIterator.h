#pragma once
#include "Iterator.h"
class NullIterator :
	public Iterator
{
public:
	NullIterator(void);
	~NullIterator(void);

	std::shared_ptr<GameComponent> Next(void);
	bool HasNext(void);
	void Remove(void);
};

