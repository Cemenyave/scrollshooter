#pragma once
#include "Unit.h"
class Player:
	public Unit
{
public:
	Player(void);
	~Player(void);

	void Update(void);
	void ControlKeyDownHandler(CL_InputEvent const &event, CL_InputState const &state);
	void ControlKeyUpHandler(CL_InputEvent const &event, CL_InputState const &state);
};

