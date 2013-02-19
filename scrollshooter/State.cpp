#include "precomp.h"
#include "State.h"
#include <algorithm>
#include <assert.h>

State::State(void){}


State::~State(void){
	RemoveAllGameObjects();
}

void State::Initialize(void){};

void State::Cleanup(void){
	RemoveAllGameObjects();
}

void State::Pause(void){}

void State::Resume(void){}

void State::Update(void){
	GameObjectIteration(mBackgroundObjects, UPDATE);
	GameObjectIteration(mGameObjects, UPDATE);
	GameObjectIteration(mEffectObjects, UPDATE);
}

void State::Draw(void){
	GameObjectIteration(mBackgroundObjects, DRAW);
	GameObjectIteration(mGameObjects, DRAW);
	GameObjectIteration(mEffectObjects, DRAW);
}

void State::AddGameObject(GameObjectPtr rGameObject, const int rType){
	if(rType == EFFECT){
		InsertByZindex(rGameObject, mEffectObjects);
	}else if(rType == GAMEOBJECT){
		InsertByZindex(rGameObject, mGameObjects);
	}else if(rType == BACKGROUND){
		InsertByZindex(rGameObject, mBackgroundObjects);
	}
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
		if(*mGameObjectIter != 0){
			if((*mGameObjectIter)->mSpawnState){
				if(rAction == UPDATE){
					(*mGameObjectIter)->Update();
				}else if(rAction == DRAW){
					//if(lastZindex > (*mGameObjectIter)->mZindex){
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

void const State::InsertByZindex(GameObjectPtr const rGameObject, GameObjectsVector &Set){
	assert(rGameObject != nullptr);
	if(Set.empty()){
		Set.push_back(GameObjectPtr(rGameObject));
		return;
	}
	if(Set.back()->mZindex <= rGameObject->mZindex){
		Set.push_back(GameObjectPtr(rGameObject));
	}else if(Set.front()->mZindex >= rGameObject->mZindex){
		Set.insert(Set.begin(), GameObjectPtr(rGameObject));
	}else{
		for(GameObjectsVector::iterator mGameObjectIter = Set.begin(); mGameObjectIter != Set.end(); mGameObjectIter++){
			if((*mGameObjectIter)->mZindex < rGameObject->mZindex){
				Set.insert(mGameObjectIter, rGameObject);
				break;
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