#include "precomp.h"
#include "Entity.h"
#include "DebugTool.h"


Entity::Entity(void):
	velocityX(0),
	velocityY(0),
	velocityVector(0),
	accelerationX(0),
	accelerationY(0),
	accelerationVector(0),
	maxVelocity(0),
	faceAngle(0)
{
}

Entity::~Entity(void){
}

void Entity::Update(void){
	GameObject::Update();
	coordX += velocityX * (deltaTime / 1000.0f);
	coordY += velocityY * (deltaTime / 1000.0f);
}

void Entity::MoveAngle(float const velocity, float const angle){
	velocityX = velocity * (cos(angle / 180.0f * std::atan(1.0f)*4.0f));
	velocityY = velocity * (sin(angle / 180.0f * std::atan(1.0f)*4.0f));
	faceAngle = angle / 180.0f * std::atan(1.0f)*4.0f;
}

void Entity::MoveLeft(float const velocity){
	MoveAngle(velocity, 180.0f);
}

void Entity::MoveRight(float const velocity){
	MoveAngle(velocity, 0.0f);
}

void Entity::MoveUp(float const velocity){
	MoveAngle(velocity, -90.0f);
}

void Entity::MoveDown(float const velocity){
	MoveAngle(velocity, 90.0f);
}

float const Entity::GetFaceAngle(void){
	return faceAngle * 180 / std::atan(1.0f)*4.0f;
}