#include "precomp.h"
#include "State.h"
#include <algorithm>
#include <assert.h>

State::State(void):
	rootGroup(new GameObjectGroup),
	backgroundGroup(new GameObjectGroup),
	gameObjectGroup(new GameObjectGroup),
	uiGroup(new GameObjectGroup)
{
	backgroundGroup->priority = 1;
	gameObjectGroup->priority = 2;
	uiGroup->priority = 3;

	rootGroup->Add(backgroundGroup);
	rootGroup->Add(gameObjectGroup);
	rootGroup->Add(uiGroup);
}


State::~State(void){
	rootGroup->ClearGroup();
}

void State::Initialize(void){};

void State::Cleanup(void){
	RemoveAllGameObjects();
}

void State::Pause(void){

}

void State::Resume(void){}

void State::Update(void){
	rootGroup->Update();

	GameObjectIteration(mBackgroundObjects, UPDATE);
	GameObjectIteration(mGameObjects, UPDATE);
	GameObjectIteration(mEffectObjects, UPDATE);
}

void State::Draw(void){
	GameObjectIteration(mBackgroundObjects, DRAW);
	GameObjectIteration(mGameObjects, DRAW);
	GameObjectIteration(mEffectObjects, DRAW);
}

void State::RemoveGameObject(GameObject *rGameObject){
	if(!mGameObjects.empty()){
		mGameObjects.erase(std::remove(mGameObjects.begin(), mGameObjects.end(), GameObjectPtr(rGameObject)), mGameObjects.end());
	}
}

void State::RemoveAllGameObjects(){
	ClearGameObjectsVector(mEffectObjects);
	ClearGameObjectsVector(mGameObjects);
	ClearGameObjectsVector(mBackgroundObjects);
}

//TODO refactoring this method. for-loop must be inside switching action. 
void State::GameObjectIteration(GameObjectsVector &Set, const int rAction){
	if(Set.size() < 1){
		return;
	}
	//int lastZindex = 0;
	for(GameObjectsVector::iterator mGameObjectIter = Set.begin(); mGameObjectIter != Set.end(); ++mGameObjectIter){
		if(Set.size() != 0){
			if((*mGameObjectIter)->spawnState){
				if(rAction == UPDATE){
					(*mGameObjectIter)->Update();
				}else if(rAction == DRAW){
					//if(lastZindex > (*mGameObjectIter)->zIndex){
						//sorting
						//mGameObjectIter = Set.begin();
						//mGameObjectIter--;
						//continue;
					//}
					(*mGameObjectIter)->Draw();
				}
			}
		}
	}
}

void State::ClearGameObjectsVector(GameObjectsVector &Set){
	while(!Set.empty()){
		Set.back()->Destroy();
		Set.pop_back();
	}
}