#include "precomp.h"
#include "Level.h"



Level::Level(void):
	Player1(new Player),
	oneEnemy(new Enemy)
{
}

void Level::Initialize(void){
	gameObjectGroup->Add(Player1);
	Player1->Spawn(350.0f, 550.0f);
	gameObjectGroup->Add(oneEnemy);
	oneEnemy->Spawn(250.0f, 250.0f);
}

void Level::Update(void){
	State::Update();
	if(keyboard.get_keycode(CL_KEY_Q)){
		Player1->TakeDamage(1);
	}
}
