#include "precomp.h"
#include "ControlsButton.h"


ControlsButton::ControlsButton(void){
	spriteCursorOn = CL_Sprite(graphicContext, "controls_button_on", &resources);
	spriteCursorOff = CL_Sprite(graphicContext, "controls_button_off", &resources);
	sprite = spriteCursorOff;
	height = 50.0f;
	width = 360.0f;
}

