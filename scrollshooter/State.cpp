#include "precomp.h"
#include "State.h"
#include "Engine.h"
#include <algorithm>

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

void State::Update(void){}

void State::Draw(Engine *rObjEngine){
	for(mGameObjectIter = mGameObjects.begin(); mGameObjectIter != mGameObjects.end(); ++mGameObjectIter){
		if(*mGameObjectIter != 0){
			if((*mGameObjectIter)->mSpawnState){
				(*mGameObjectIter)->Draw(rObjEngine);
			}
		}
	}
}

void State::AddGameObject(GameObject *rGameObject){
	mGameObjects.push_back(GameObjectPtr(rGameObject));
}

void State::RemoveGameObject(GameObject *rGameObject){
	if(!mGameObjects.empty()){
		mGameObjects.erase(std::remove(mGameObjects.begin(), mGameObjects.end(), GameObjectPtr(rGameObject)), mGameObjects.end());
	}
}

void State::RemoveAllGameObjects(){
	while(!mGameObjects.empty()){
		mGameObjects.back()->Destroy(this);
		mGameObjects.pop_back();
	}
}