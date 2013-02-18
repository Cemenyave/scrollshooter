#include "precomp.h"
#include "NewGameButton.h"


NewGameButton::NewGameButton(void){
	Engine &ObjEngine = Engine::GetEngine();
	mSpriteCursorOn = CL_Sprite(ObjEngine.mGraphicContext, "new_game_button_on", ObjEngine.GetResources());
	mSpriteCursorOff = CL_Sprite(ObjEngine.mGraphicContext, "new_game_button_off", ObjEngine.GetResources());
	mSprite = mSpriteCursorOff;
	mHeight = 50.0f;
	mWidth = 360.0f;
}