#include "precomp.h"
#include "NullIterator.h"


NullIterator::NullIterator(void)	
{
}


NullIterator::~NullIterator(void){
}

std::shared_ptr<GameComponent> NullIterator::Next(void){
	return false;
}

bool NullIterator::HasNext(void){
	return false;
}