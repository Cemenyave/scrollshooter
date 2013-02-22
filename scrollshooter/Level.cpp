#include "precomp.h"
#include "Level.h"



Level::Level(void){
}

void Level::Initialize(void){
	Player1 = GameObjectFactory<Player>(GAMEOBJECT);
	Player1->Spawn(350.0f, 550.0f);

	oneEnemy = GameObjectFactory<Enemy>(GAMEOBJECT);
	oneEnemy->Spawn(250.0f, 250.0f);
}

void Level::Update(void){
	State::Update();
	if(keyboard.get_keycode(CL_KEY_Q)){
		Player1->TakeDamage(1);
	}
}
