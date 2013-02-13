#include "precomp.h"
#include "ObjectButton.h"
#include "State.h"

ObjectButton::ObjectButton(State * const  rState):GameObject(rState){
	mHovered = false;
	mClickHandler = nullptr;
	mHoverHandler = nullptr;
}


ObjectButton::~ObjectButton(void){
	mClickHandler = nullptr;
	mHoverHandler = nullptr;
}

void ObjectButton::ClickEventHandler(Engine *rObjEngine){
//	if(mClickHandler){
//		mClickHandler->Handle();
//	}
}

void ObjectButton::HoverEventHandler(Engine *rObjEngine){
	if(mHovered){
		mHovered = false;
		return;
	}
	mHovered = true;
}
//
//void ObjectButton::SetClickHandler(Handler *rObjHandler){
//	mClickHandler = rObjHandler;
//}
//
//void ObjectButton::SetHoverHandler(Handler *rObjHandler){
//	mHoverHandler = rObjHandler;
//}