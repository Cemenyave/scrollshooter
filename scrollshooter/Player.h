#pragma once
#include "Unit.h"
class Player:
	public Unit
{
	const static int TURNING_LEFT = -1;
	const static int TURNING_RIGHT = 1;
	const static int STANDING = 0;

	int currentState;
	int currentSprite;
	CL_Sprite turnLeftFromIdleSprite;
	CL_Sprite turnRightFromIdleSprite;
	CL_Sprite idleSprite;

	void Animate(void);
	void SetSprite(CL_Sprite newSprite);
	void ReverseAnimation(void);
public:
	Player(void);
	~Player(void);

	void Update(void);
	void ControlKeyDownHandler(CL_InputEvent const &event, CL_InputState const &state);
	void ControlKeyUpHandler(CL_InputEvent const &event, CL_InputState const &state);
};

