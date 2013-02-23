#include "precomp.h"
#include "Iterator.h"


Iterator::Iterator(void){
}


Iterator::~Iterator(void){
}

std::shared_ptr<GameComponent> Iterator::Next(void){
	return false;
}

bool Iterator::HasNext(void){
	return false;
}

void Iterator::Remove(void){
}