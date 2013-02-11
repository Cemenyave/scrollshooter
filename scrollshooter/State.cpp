#include "precomp.h"
#include "State.h"
#include "Engine.h"
#include <algorithm>

/// <summary>
/// Initializes a new instance of the <see cref="State"/> class.
/// </summary>
State::State(void)
{
}


State::~State(void)
{
}

/// <summary>
/// Initializes the specified r obj engine.
/// </summary>
/// <param name="rObjEngine">The r obj engine.</param>
void State::Initialize(Engine *rObjEngine)
{
}

/// <summary>
/// Cleanups the State.
/// </summary>
/// <param name="rObjEngine">The pointer to Engine object.</param>
void State::Cleanup(Engine *rObjEngine)
{
	RemoveAllGameObjects();
}

/// <summary>
/// Pauses this instance.
/// </summary>
void State::Pause(void)
{
}

/// <summary>
/// Resumes this instance.
/// </summary>
void State::Resume(void)
{
}

void State::Update(void)
{

}
	
void State::Draw(Engine *rObjEngine)
{
	for(mGameObjectIter = mGameObjects.begin(); mGameObjectIter != mGameObjects.end(); ++mGameObjectIter)
    {
		if(*mGameObjectIter != 0)
		{
			if((*mGameObjectIter)->IsSpawned())
			{
				(*mGameObjectIter)->Draw(rObjEngine);
			}
		}
	}
}

void State::AddGameObject(GameObject *rGameObject)
{
	mGameObjects.push_back(GameObjectShPtr(rGameObject));
}

void State::RemoveGameObject(GameObject *rGameObject)
{
	if(!mGameObjects.empty())
	{
		mGameObjects.erase(std::remove(mGameObjects.begin(), mGameObjects.end(), GameObjectShPtr(rGameObject)), mGameObjects.end());
	}
}

void State::RemoveAllGameObjects()
{
	while(!mGameObjects.empty())
	{
		mGameObjects.pop_back();
		//mGameObjects.back()->Destroy(this);
	}
}