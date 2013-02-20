#include "precomp.h"
#include "Star.h"


Star::Star(void){
	sprite = CL_Sprite(graphicContext,"stars", &resources);
	sprite.set_frame(rand() % 5);
	sprite.set_delay((rand() % 500) + 100);
	zIndex = 3;
	width = 10.0f;
	height = 10.0f;
}
