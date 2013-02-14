#include "precomp.h"
#include "ObjectButton.h"
#include "State.h"

ObjectButton::ObjectButton(State * const  rState):GameObject(rState){
	mOnHover = false;
	mOnClick = false;
	mClickHandler = nullptr;
	mHoverHandler = nullptr;
}


ObjectButton::~ObjectButton(void){
	mClickHandler = nullptr;
	mHoverHandler = nullptr;
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
		mColor = CL_Colorf::blueviolet;
		if(rObjEngine->mMouse.get_keycode(CL_MOUSE_LEFT)){
			mOnClick = true;
			mColor = CL_Colorf::red;
		}else{
			mOnClick = false;
		}
	}else {
		mOnHover = false;
		mOnClick = false;
		mColor = CL_Colorf(255/255.0f, 234/255.0f, 117/255.0f);
	}
}