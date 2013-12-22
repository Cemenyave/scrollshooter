#pragma once
#include "GameObject.h"
#include "Engine.h"

class ObjectButton :
	public GameObject
{
protected:
	CL_Sprite spriteCursorOn;
	CL_Sprite spriteCursorOff;
	CL_Slot handler;
public:
	ObjectButton();
	bool mOnHover;
	bool mOnClick;
	
	template <typename _Type>
	void SetHandler(_Type *instance, void (_Type::*handlerFunction)(CL_InputEvent const &event, CL_InputState const &state)){
		handler = keyboard.sig_key_down().connect(instance, handlerFunction);
		handler.enable();
	}
	
	virtual void Hover(void);
	virtual void Disable(void);
	virtual void Enable(void);
};