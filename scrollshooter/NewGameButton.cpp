#include "precomp.h"
#include "NewGameButton.h"


NewGameButton::NewGameButton(void){
	spriteCursorOn = CL_Sprite(graphicContext, "new_game_button_on", &resources);
	spriteCursorOff = CL_Sprite(graphicContext, "new_game_button_off", &resources);
	sprite = spriteCursorOff;
	height = 50.0f;
	width = 360.0f;
}