#include "precomp.h"
#include "Level.h"


Level::Level(void){
}

void Level::Initialize(void){
	Player1 = GameObjectFactory<Player>(GAMEOBJECT);
	Player1->Spawn(350.0f, 550.0f);
}
