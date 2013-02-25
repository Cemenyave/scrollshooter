#include "precomp.h"
#include "CompositeIterator.h"
#include "GameComponent.h"
#include "GameObjectGroup.h"

CompositeIterator::CompositeIterator(std::vector<gameComponentPtr> *elementsVector){
	stack.push_back(*this);
	currentIter = elementsVector->begin();
	lastElement = elementsVector->end();
}

CompositeIterator::~CompositeIterator(void){
}

std::shared_ptr<GameComponent> CompositeIterator::Next(void){
	if(HasNext()){
		CompositeIterator iter = (CompositeIterator)stack.back();
		CompositeIterator * cIter = dynamic_cast<CompositeIterator*>(&iter);
		std::shared_ptr<GameComponent> component = *(++cIter->currentIter);
		GameObjectGroup* group = dynamic_cast<GameObjectGroup*>(component.get());
		if(group){
			stack.push_back(group->CreateIterator());
		}
		return component;
	}
}

bool CompositeIterator::HasNext(void){
	if(stack.empty()){
		return false;
	}else{
		CompositeIterator *iter = &stack.back();
		if(iter->currentIter != iter->lastElement){
			return true;
		}else{
			stack.pop_back();
			return stack.back().HasNext();
		}
	}
}