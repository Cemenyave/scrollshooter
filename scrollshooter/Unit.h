#pragma once
#include "Entity.h"

//here will be implemented collision detection
class Unit :
	public Entity
{
protected:
	int hitPoints;
public:
	Unit(void);
	void Update(void);
	void TakeDamage(int);
};

