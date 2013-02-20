#include "precomp.h"
#include "QuitButton.h"


QuitButton::QuitButton(void){
	spriteCursorOn = CL_Sprite(graphicContext, "quit_button_on", resources);
	spriteCursorOff = CL_Sprite(graphicContext, "quit_button_off", resources);
	sprite = spriteCursorOff;
	height = 50.0f;
	width = 360.0f;
}
