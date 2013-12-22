#include "precomp.h"
#include "Engine.h"
#include "Player.h"
#include "DebugTool.h"


Player::Player(void):
	idleSprite(),
	turnLeftFromIdleSprite(),
	turnRightFromIdleSprite()
{
	idleSprite = CL_Sprite(graphicContext, "player_idle", resources);
	turnLeftFromIdleSprite = CL_Sprite(graphicContext, "player_turn_left_from_idle", resources);
	turnRightFromIdleSprite = CL_Sprite(graphicContext, "player_turn_right_from_idle", resources);
	hitPoints = 3;
	width = 41.0f;
	height = 64.0f;
	currentState = Player::STANDING;
	sprite.clone(idleSprite);
}

Player::~Player(void){
}

void Player::Update(void){
	Unit::Update();
	
	if(keyboard.get_keycode(CL_KEY_W) || keyboard.get_keycode(CL_KEY_UP)){
		MoveUp(300);
	}else if(keyboard.get_keycode(CL_KEY_S) || keyboard.get_keycode(CL_KEY_DOWN)){
		MoveDown(300);
	}else{
		velocityY = 0.0f;
	}

	if(keyboard.get_keycode(CL_KEY_A) || keyboard.get_keycode(CL_KEY_LEFT)){
		MoveLeft(300);
	}else if(keyboard.get_keycode(CL_KEY_D) || keyboard.get_keycode(CL_KEY_RIGHT)){
		MoveRight(300);
	}else{
		velocityX = 0.0f;
	}
	Animate();
}

void Player::Destroy(void){
	Unit::Destroy();
	Engine::GetEngine().Debugger->Log("Player was destroyed");
}

void Player::Animate(void){
	if(velocityX > 0.0f){
		if(currentState != Player::TURNING_RIGHT){
			SetSprite(turnRightFromIdleSprite);
			currentState = Player::TURNING_RIGHT;
			return;
		}
	}
	if(velocityX < 0.0f){
		if(currentState != Player::TURNING_LEFT){
			SetSprite(turnLeftFromIdleSprite);
			currentState = Player::TURNING_LEFT;
			return;
		}
	}
	if(velocityX == 0.0f){
		if(currentState != Player::STANDING){
			ReverseAnimation();
			CL_Slot animationCallback = sprite.sig_animation_finished().connect(this, &Player::SetSprite, idleSprite);
			currentState = Player::STANDING;
		}
	}
}

void Player::SetSprite(CL_Sprite newSprite){
	sprite.set_image_data(newSprite);
}

void Player::ReverseAnimation(void){
	sprite.set_play_backward(sprite.is_play_backward() ? false : true);
	sprite.restart();
	if(sprite.get_show_on_finish() == sprite.show_blank){
		return;
	}
	sprite.set_show_on_finish(sprite.get_show_on_finish() == sprite.show_first_frame ? sprite.show_last_frame : sprite.show_first_frame);
}