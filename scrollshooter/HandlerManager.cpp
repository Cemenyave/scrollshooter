#include "precomp.h"
#include "HandlerManager.h"
#include <assert.h>


HandlerManager::HandlerManager(void)
{
}


HandlerManager::~HandlerManager(void)
{
}

Handler *HandlerManager::AddHandler(Handler *rHandler){
	assert(rHandler != nullptr);
	mHandlerPool.push_back(HandlerPtr(rHandler));
	return &(*mHandlerPool.back());
}

void HandlerManager::RegistrHandlerType(std::string rhandlerType){
}

void HandlerManager::ClearHandlerPool(void){
	while(!mHandlerPool.empty()){
		mHandlerPool.pop_back();
	}
}