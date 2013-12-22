#include "precomp.h"
#include "CreditsButton.h"


CreditsButton::CreditsButton(void){
	spriteCursorOn = CL_Sprite(graphicContext, "credits_button_on", resources);
	spriteCursorOff = CL_Sprite(graphicContext, "credits_button_off", resources);
	sprite = spriteCursorOff;
	height = 50.0f;
	width = 360.0f;
}

