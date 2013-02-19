#include "precomp.h"
#include "Base.h"


Base::Base(void):
	mGraphicContext(Engine::GetEngine().mGraphicContext),
	mKeyboard(Engine::GetEngine().mKeyboard),
	mMouse(Engine::GetEngine().mMouse),
	mSlotInput(Engine::GetEngine().mSlotInput)
{
	
}


Base::~Base(void){
}

void Base::Update(void){
	Engine &ObjEngine = Engine::GetEngine();
	mDeltaTime = ObjEngine.mDeltaTime;
}