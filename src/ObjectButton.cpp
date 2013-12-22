#include "precomp.h"
#include "ObjectButton.h"

ObjectButton::ObjectButton():
	spriteCursorOn(),
	spriteCursorOff()
{
	mOnHover = false;
	mOnClick = false;
}

void ObjectButton::Hover(void){
	mOnHover = mOnHover ? false : true;
	if(mOnHover){
		sprite = spriteCursorOn;
	}else{
		sprite = spriteCursorOff;
	}
}

void ObjectButton::Disable(void){
	handler.disable();
}

void ObjectButton::Enable(void){
	handler.enable();
}