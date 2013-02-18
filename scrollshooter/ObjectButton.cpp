#include "precomp.h"
#include "ObjectButton.h"

ObjectButton::ObjectButton(){
	mOnHover = false;
	mOnClick = false;
}



void ObjectButton::Hover(void){
	mOnHover = mOnHover ? false : true;
	if(mOnHover){
		mSprite = mSpriteCursorOn;
	}else{
		mSprite = mSpriteCursorOff;
	}
}