#pragma once
#include "GameComponent.h"
class GameObjectGroup :
	public GameComponent
{
	typedef std::shared_ptr<GameComponent> gameComponentPtr;

	std::vector<gameComponentPtr> elements;
public:
	std::vector<gameComponentPtr>::iterator elemIter;

	GameObjectGroup(void);
	~GameObjectGroup(void);

	void Add(std::shared_ptr<GameComponent> newItem);
	void Remove(std::shared_ptr<GameComponent> elemForErase);
	void GetChild(void);
	bool HasChilde(void);
	void ClearGroup(void);
	void Update(void);
	void Draw(void);
};

