#pragma once
#include "state.h"
#include "Player.h"

class Level :
	public State
{
public:
	std::shared_ptr<Player> Player1;

	Level(void);
	void Initialize(void);
};

