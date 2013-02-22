#pragma once
#include "state.h"
#include "Player.h"
#include "Enemy.h"

class Level :
	public State
{
public:
	std::shared_ptr<Player> Player1;
	std::shared_ptr<Enemy> oneEnemy;

	Level(void);
	void Initialize(void);
	void Update(void);
};

