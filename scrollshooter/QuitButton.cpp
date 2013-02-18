#include "precomp.h"
#include "QuitButton.h"


QuitButton::QuitButton(void){
	Engine &ObjEngine = Engine::GetEngine();
	mSpriteCursorOn = CL_Sprite(ObjEngine.mGraphicContext, "quit_button_on", ObjEngine.GetResources());
	mSpriteCursorOff = CL_Sprite(ObjEngine.mGraphicContext, "quit_button_off", ObjEngine.GetResources());
	mSprite = mSpriteCursorOff;
	mHeight = 50.0f;
	mWidth = 360.0f;
}
