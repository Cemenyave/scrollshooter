#include "precomp.h"
#include "Base.h"

Base::Base(void):
	graphicContext(Engine::GetEngine().graphicContext),
	keyboard(Engine::GetEngine().keyboard),
	mouse(Engine::GetEngine().mouse),
	resources(Engine::GetEngine().GetResources()),
	deltaTime(Engine::GetEngine().deltaTime)
{
	
}


Base::~Base(void){
}

void Base::Update(void){
}

void Base::Draw(void){
}