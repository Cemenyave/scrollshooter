#include "precomp.h"
#include "ClickTest1ButtonHandler.h"
#include "GameObject.h"



ClickTest1ButtonHandler::ClickTest1ButtonHandler(void)
{
}


ClickTest1ButtonHandler::~ClickTest1ButtonHandler(void)
{
}

void ClickTest1ButtonHandler::Handle(GameObject *rObjGameObject, State *rState){
	rObjGameObject->Destroy(rState);
}