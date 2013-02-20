#include "precomp.h"
#include "GameObject.h"
#include "State.h"
#include <assert.h>

GameObject::GameObject(void):
	width(0),
	height(0),
	coordX(0),
	coordY(0),
	zIndex(0),
	spawnState(false),
	color(),
	sprite()
{
	zIndex = 1;
	color = CL_Colorf(255/255.0f, 234/255.0f, 117/255.0f);
}

GameObject::~GameObject(){}

bool GameObject::Spawn(float rCoordX, float rCoordY){
	coordX = rCoordX;
	coordY = rCoordY;
	spawnState = true;
	return true;
}

void GameObject::Draw(void){
	if(!sprite.is_null()){
		sprite.update();
		sprite.draw(graphicContext, coordX, coordY);
	}else {
		CL_Draw::fill(graphicContext, coordX, coordY, coordX + width, coordY + height, color);
	}
}

void GameObject::Destroy(void){
	spawnState = false;
}

//dose not work with rotating object
float const GameObject::GetCentrePointX(void){
	if(spawnState){
		return coordX - width / 2;
	}
	return -1.0f;
}

//dose not work with rotating object
float const GameObject::GetCentrePointY(void){
	if(spawnState){
		return coordY - width / 2;
	}
	return -1.0f;
}