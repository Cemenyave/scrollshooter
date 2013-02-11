#pragma once
#include "Engine.h"

class GameObject
{
	float mWidth;
	float mHeight;

	float mCoordX;
	float mCoordY;

	bool mSpawnState;

	CL_Colorf mColor;
	CL_Sprite mSprite;
public:
	GameObject(State *rState);
	GameObject(void){};
	//GameObject(int rWidth, int rHeight, CL_Color rColor = CL_Color::CL_Color(100, 100, 100));
	~GameObject(void);
	
	/// <summary>
	/// Sets the width.
	/// </summary>
	/// <param name="rWidth">Width of the r.</param>
	void SetWidth(float rWidth);
	
	/// <summary>
	/// Gets the width.
	/// </summary>
	/// <returns></returns>
	float GetWidth(void);

	/// <summary>
	/// Sets the height.
	/// </summary>
	/// <param name="rHeight">Height of the r.</param>
	void SetHeight(float rHeight);

	/// <summary>
	/// Gets the height.
	/// </summary>
	/// <returns></returns>
	float GetHeight(void);

	/// <summary>
	/// Gets the color.
	/// </summary>
	/// <returns></returns>
	CL_Color GetColor(void);

	/// <summary>
	/// Spawns the specified r coord X.
	/// </summary>
	/// <param name="rCoordX">The r coord X.</param>
	/// <param name="rCoordY">The r coord Y.</param>
	/// <returns></returns>
	bool Spawn(float rCoordX, float rCoordY);

	/// <summary>
	/// Determines whether this instance is spawned.
	/// </summary>
	/// <returns></returns>
	bool IsSpawned();

	/// <summary>
	/// Draws this instance.
	/// </summary>
	void Draw(Engine *rObjEngine);

	/// <summary>
	/// Calls the destructor.
	/// </summary>
	void Destroy(State *rState);
};