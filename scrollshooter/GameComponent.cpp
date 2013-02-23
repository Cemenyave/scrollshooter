#include "precomp.h"
#include "GameComponent.h"
#include "NullIterator.h"


GameComponent::GameComponent(void):
	priority(1),
	parent(0)
{

}

GameComponent::~GameComponent(void){
	Base::~Base();
}

void GameComponent::Add(std::shared_ptr<GameComponent> newItem){
	throw new CL_Exception("Unsupported Member");
}

void GameComponent::Remove(std::shared_ptr<GameComponent> elemForErase){
	throw new CL_Exception("Unsupported Member");
}

void GameComponent::GetChild(void){
	throw new CL_Exception("Unsupported Member");
}

bool GameComponent::HasChild(void){
	return false;
}

Iterator GameComponent::CreateIterator(){
	iterator = new NullIterator;
}