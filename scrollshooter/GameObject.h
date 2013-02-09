#pragma once

class GameObject
{
	int mWidth;
	int mHeight;
	CL_Sprite mSprite;
public:
	GameObject(void);
	void SetWidth(int rWidth);
	void SetHeight(int rHeight);
	bool Spawn(int rCoordX, int rCoordY);
};