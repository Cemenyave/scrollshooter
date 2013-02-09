#include "precomp.h"
#include "MainState.h"
#include "Engine.h"


MainState::MainState(void)
{
}

MainState::~MainState(void)
{
}

void MainState::Initialize(Engine *rObjEngine){
	mFont = CL_Font(rObjEngine->mGraphicContext, "Tahoma", 30);
}

void MainState::Drow(void)
{
	
}