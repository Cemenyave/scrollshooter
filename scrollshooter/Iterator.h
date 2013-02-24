#pragma once

class GameComponent;

//Base class for GameComponents Iterator
class Iterator
{
public:
	typedef std::shared_ptr<GameComponent> gameComponentPtr;

	std::vector<gameComponentPtr> *collection;
	std::vector<gameComponentPtr>::iterator collectionIter;

	Iterator(std::vector<gameComponentPtr> *rCollection);
	virtual ~Iterator(void);

	virtual gameComponentPtr Next(void);
	virtual bool HasNext(void);
	virtual void Remove(void);
};