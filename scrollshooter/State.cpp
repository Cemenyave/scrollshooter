#include "precomp.h"
#include "State.h"
#include "Engine.h"
#include <algorithm>
#include <assert.h>

State::State(void){}


State::~State(void){
	RemoveAllGameObjects();
}

void State::Initialize(Engine *rObjEngine){};

void State::Cleanup(Engine *rObjEngine){
	RemoveAllGameObjects();
}

void State::Pause(void){}

void State::Resume(void){}

void State::Update(Engine *rObjEngine){
	GameObjectIteration(mBackgroundObjects, UPDATE, rObjEngine);
	GameObjectIteration(mGameObjects, UPDATE, rObjEngine);
	GameObjectIteration(mEffectObjects, UPDATE, rObjEngine);
}

void State::Draw(Engine *rObjEngine){
	GameObjectIteration(mBackgroundObjects, DRAW, rObjEngine);
	GameObjectIteration(mGameObjects, DRAW, rObjEngine);
	GameObjectIteration(mEffectObjects, DRAW, rObjEngine);
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

void State::GameObjectIteration(GameObjectsVector &Set, const int rAction, Engine *rObjEngine){
	if(Set.size() < 1){
		return;
	}
	for(mGameObjectIter = Set.begin(); mGameObjectIter != Set.end(); ++mGameObjectIter){
		if(*mGameObjectIter != 0){
			if((*mGameObjectIter)->mSpawnState){
				if(rAction == UPDATE){
					(*mGameObjectIter)->Update(rObjEngine);
				}else if(rAction == DRAW){
					(*mGameObjectIter)->Draw(rObjEngine);
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
		for(mGameObjectIter = Set.begin(); mGameObjectIter != Set.end(); mGameObjectIter++){
			if((*mGameObjectIter)->mZindex < rGameObject->mZindex){
				Set.insert(mGameObjectIter, rGameObject);
				break;
			}
		}
	}
}

void State::ClearGameObjectsVector(GameObjectsVector &Set){
	while(!Set.empty()){
		Set.back()->Destroy(this);
		Set.pop_back();
	}
}