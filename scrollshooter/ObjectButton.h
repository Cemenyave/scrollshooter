#pragma once
#include "GameObject.h"
#include "Engine.h"

class ObjectButton :
	public GameObject
{
protected:
	CL_Sprite mSpriteCursorOn;
	CL_Sprite mSpriteCursorOff;
public:
	ObjectButton();
	bool mOnHover;
	bool mOnClick;
	
	template <typename _Type>
	void SetHandler(_Type *instance, void (_Type::*handler)(CL_InputEvent const &event, CL_InputState const &state)){
		Engine &ObjEngine = Engine::GetEngine();
		ObjEngine.slot_key_down.connect(ObjEngine.mKeyboard.sig_key_down(), instance, handler);
	}
	
	virtual void Hover(void);
};