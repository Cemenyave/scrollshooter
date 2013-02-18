#include "precomp.h"
#include "ControlsButton.h"


ControlsButton::ControlsButton(void){
	Engine &ObjEngine = Engine::GetEngine();
	mSpriteCursorOn = CL_Sprite(ObjEngine.mGraphicContext, "controls_button_on", ObjEngine.GetResources());
	mSpriteCursorOff = CL_Sprite(ObjEngine.mGraphicContext, "controls_button_off", ObjEngine.GetResources());
	mSprite = mSpriteCursorOff;
	mHeight = 50.0f;
	mWidth = 360.0f;
}

