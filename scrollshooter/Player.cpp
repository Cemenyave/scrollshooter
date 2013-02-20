#include "precomp.h"
#include "Engine.h"
#include "Player.h"
#include "DebugTool.h"


Player::Player(void):
	idleSprite(),
	turnLeftSprite(),
	turnRightSprite()
{
	//turnLeftSprite = CL_Sprite(graphicContext, "player_turn_left", &resources);
	//turnRightSprite = CL_Sprite(graphicContext, "player_turn_right", &resources);
	idleSprite = CL_Sprite(graphicContext, "player_idle", resources);
	HitPoints = 3;
	width = 41.0f;
	height = 64.0f;
	sprite = idleSprite;
}


Player::~Player(void){
}

void Player::Update(void){
	Unit::Update();
	
	if(keyboard.get_keycode(CL_KEY_W) || keyboard.get_keycode(CL_KEY_UP)){
		MoveUp(200);
	}else if(keyboard.get_keycode(CL_KEY_S) || keyboard.get_keycode(CL_KEY_DOWN)){
		MoveDown(200);
	}else{
		velocityY = 0.0f;
	}

	if(keyboard.get_keycode(CL_KEY_A) || keyboard.get_keycode(CL_KEY_LEFT)){
		MoveLeft(200);
	}else if(keyboard.get_keycode(CL_KEY_D) || keyboard.get_keycode(CL_KEY_RIGHT)){
		MoveRight(200);
	}else{
		velocityX = 0.0f;
	}
}

