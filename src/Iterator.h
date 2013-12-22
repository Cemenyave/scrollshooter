#pragma once

class GameComponent;

//Base virtual class for GameComponents Iterator
class Iterator
{
public:
	//type definitions
	typedef std::shared_ptr<GameComponent> gameComponentPtr;

	//methods
	Iterator(void);
	virtual ~Iterator(void);

	virtual gameComponentPtr Next(void);
	virtual bool HasNext(void);
	virtual void Remove(void);
};