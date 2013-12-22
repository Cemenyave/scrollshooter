#include "precomp.h"
#include "Iterator.h"

Iterator::Iterator(void){
}

Iterator::~Iterator(void){
}

std::shared_ptr<GameComponent> Iterator::Next(void){
	throw new CL_Exception("Unsupported Method. Iterator is just interface.");
}

bool Iterator::HasNext(void){
	throw new CL_Exception("Unsupported Method. Iterator is just interface.");
}

void Iterator::Remove(void){
	throw new CL_Exception("Unsupported Method. Iterator is just interface.");
}