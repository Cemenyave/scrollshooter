#include "precomp.h"
#include "Enemy.h"


Enemy::Enemy(void){
	width = 50.0f;
	height = 50.0f;
	hitPoints = 3;
}


Enemy::~Enemy(void){
	Unit::~Unit();
}
