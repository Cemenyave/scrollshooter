#include "precomp.h"
#include "GameObjectGroup.h"

#include "DebugTool.h"


GameObjectGroup::GameObjectGroup(void):
	elements(),
	elemIter()
{
}

GameObjectGroup::~GameObjectGroup(void){
	ClearGroup();
}

Iterator *GameObjectGroup::CreateIterator(void){
	return new CompositeIterator(&elements);
}

//Adds new item into group by his priority
void GameObjectGroup::Add(std::shared_ptr<GameComponent> newItem){
	if(elements.empty()){
		elements.push_back(newItem);
		return;
	}
	if(elements.back()->priority <= newItem->priority){
		elements.push_back(newItem);
	}else if(elements.front()->priority >= newItem->priority){
		elements.insert(elements.begin(), newItem);
	}else{
		for(std::vector<gameComponentPtr>::iterator elementsIter = elements.begin(); elementsIter != elements.end(); elementsIter++){
			if((*elementsIter)->priority < newItem->priority){
				elements.insert(elementsIter, newItem);
				break;
			}
		}
	}
}

bool GameObjectGroup::HasChilde(void){
	if(elements.size() > 0){
		return true;
	}
	return false;
}

// TODO: I got some questions here. MB i should rework this... 
void GameObjectGroup::Remove(std::shared_ptr<GameComponent> elemForRemove){
	for(elemIter = elements.begin(); elemIter != elements.end(); elemIter++){
		if((*elemIter) == elemForRemove){
			elements.erase(elemIter);
			return;
		}
		if((*elemIter)->HasChild()){
			(*elemIter)->Remove(elemForRemove);
		}
	}
	Engine::GetEngine().Debugger->Log("Object was not deleted");
}

void GameObjectGroup::ClearGroup(void){
	while(!elements.empty()){
		GameObjectGroup *group = dynamic_cast<GameObjectGroup *>(elements.back().get()); 
		if(group){
			group->ClearGroup();
		}
		elements.pop_back();
	}
}

void GameObjectGroup::Update(void){
	GameComponent::Update();
	for(elemIter = elements.begin(); elemIter != elements.end(); elemIter++){
		(*elemIter)->Update();
		UpdateHook((*elemIter));
	}
}

void GameObjectGroup::UpdateHook(gameComponentPtr rGameObject){
	return;
}

void GameObjectGroup::Draw(void){
	GameComponent::Draw();
	for(elemIter = elements.begin(); elemIter != elements.end(); elemIter++){
		(*elemIter)->Draw();
		DrawHook((*elemIter));
	}
}

void GameObjectGroup::DrawHook(gameComponentPtr rGameObject){
	return;
}