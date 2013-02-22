#pragma once
#include "base.h"
class GameComponent :
	public Base
{
public:
	GameComponent(void);
	~GameComponent(void);

	virtual void Add(void);
	virtual void Remove(void);
	virtual void GetChild(void);
	void Update(void);
	void Draw(void);
};

