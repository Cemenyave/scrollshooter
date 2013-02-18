#include "precomp.h"
#include "Star.h"


Star::Star(void){
	Engine &ObjEngine  = Engine::GetEngine();
	mSprite = CL_Sprite(ObjEngine.mGraphicContext,"stars", ObjEngine.GetResources());
	mSprite.set_frame(rand() % 5);
	mSprite.set_delay((rand() % 500) + 100);
	mZindex = 3;
	mWidth = 10.0f;
	mHeight = 10.0f;
}
