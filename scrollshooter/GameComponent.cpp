#include "precomp.h"
#include "GameComponent.h"
#include "NullIterator.h"


GameComponent::GameComponent(void):
	priority(1)
{

}

GameComponent::~GameComponent(void){
	Base::~Base();
}

void GameComponent::Add(std::shared_ptr<GameComponent> newItem){
	throw new CL_Exception("Unsupported Method");
}

void GameComponent::Remove(std::shared_ptr<GameComponent> elemForErase){
	throw new CL_Exception("Unsupported Method");
}

void GameComponent::GetChild(void){
	throw new CL_Exception("Unsupported Method");
}

bool GameComponent::HasChild(void){
	return false;
}

Iterator *GameComponent::CreateIterator(){
	return new NullIterator();
}