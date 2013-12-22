#pragma once
#include "GameObject.h"
class Entity :
	public GameObject
{
protected:
	float velocityX;
	float velocityY;
	float velocityVector;
	float accelerationX;
	float accelerationY;
	float accelerationVector;
	float maxVelocity;
	float faceAngle; // in radians
public:
	Entity(void);
	~Entity(void);

	void Update(void);
	void MoveAngle(float const speed = 0, float const angle = 0);
	void MoveLeft(float const speed);
	void MoveRight(float const speed);
	void MoveUp(float const speed);
	void MoveDown(float const speed);
	float const GetFaceAngle(void); //in degrees
};