#include "precomp.h"
#include "CreditsButton.h"


CreditsButton::CreditsButton(void){
	Engine &ObjEngine = Engine::GetEngine();
	mSpriteCursorOn = CL_Sprite(ObjEngine.mGraphicContext, "credits_button_on", ObjEngine.GetResources());
	mSpriteCursorOff = CL_Sprite(ObjEngine.mGraphicContext, "credits_button_off", ObjEngine.GetResources());
	mSprite = mSpriteCursorOff;
	mHeight = 50.0f;
	mWidth = 360.0f;
}

