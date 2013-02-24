#include "precomp.h"
#include "Iterator.h"


Iterator::Iterator(std::vector<gameComponentPtr> *rCollection):
	collection(),
	collectionIter()
{
	collection = rCollection;
	collectionIter = collection->begin();
}


Iterator::~Iterator(void){
}

std::shared_ptr<GameComponent> Iterator::Next(void){
	collectionIter++;
	if(collectionIter != collection->end()){
		return (*collectionIter);
	}
}

bool Iterator::HasNext(void){
	return false;
}

void Iterator::Remove(void){
}