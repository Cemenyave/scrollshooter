#include "precomp.h"
#include "ObjectButton.h"

ObjectButton::ObjectButton(){
	mOnHover = false;
	mOnClick = false;
}


ObjectButton::~ObjectButton(void){
}

void ObjectButton::ClickEventHandler(Engine *rObjEngine){
}

void ObjectButton::HoverEventHandler(Engine *rObjEngine){
}

void ObjectButton::Update(Engine *rObjEngine){
	int mouseX = rObjEngine->mMouse.get_x();
	int mouseY = rObjEngine->mMouse.get_y();
	if(mouseX < mCoordX + mWidth && mouseX > mCoordX && mouseY < mCoordY + mHeight && mouseY > mCoordY){
		mOnHover = true;
		if(rObjEngine->mMouse.get_keycode(CL_MOUSE_LEFT)){
			mOnClick = true;
		}else{
			mOnClick = false;
		}
	}else {
		mOnHover = false;
		mOnClick = false;
	}
}