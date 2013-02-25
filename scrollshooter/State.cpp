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
}

void State::Pause(void){
}

void State::Resume(void){}

void State::Update(void){
	rootGroup->Update();
}

void State::Draw(void){
	rootGroup->Draw();
}