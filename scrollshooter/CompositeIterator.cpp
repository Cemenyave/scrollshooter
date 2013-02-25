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
		Iterator iter = (Iterator)stack.back();
		CompositeIterator * cIter = dynamic_cast<CompositeIterator*>(&iter);
		if(cIter){
			std::shared_ptr<GameComponent> component = *(++cIter->currentIter);
			GameObjectGroup* group = dynamic_cast<GameObjectGroup*>(component.get());
			if(group){
				stack.push_back(group->CreateIterator());
			}
			return component;
		}else{
			return iter.Next();
		}
	}
	throw new CL_Exception("No more element");
}

bool CompositeIterator::HasNext(void){
	if(stack.empty()){
		return false;
	}else{
		Iterator *iter = &stack.back();
		CompositeIterator *cIter = dynamic_cast<CompositeIterator*>(iter);
		if(cIter){
			if(cIter->currentIter != cIter->lastElement){
				return true;
			}else{
				stack.pop_back();
				return stack.back().HasNext();
			}
		}else{
			return iter->HasNext();
		}
	}
}