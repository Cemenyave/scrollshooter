#pragma once
#include "GameComponent.h"
#include "CompositeIterator.h"

class GameObjectGroup :
	public GameComponent
{
public:
	//members
	CompositeIterator myIterator;
	std::vector<gameComponentPtr> elements;

	std::vector<gameComponentPtr>::iterator elemIter;
	//methods
	GameObjectGroup(void);
	~GameObjectGroup(void);
	Iterator CreateIterator(void);
	void Add(std::shared_ptr<GameComponent> newItem);
	void Remove(std::shared_ptr<GameComponent> elemForErase);
	void GetChild(void);
	bool HasChilde(void);
	void ClearGroup(void);
	void Update(void);
	void Draw(void);
};

