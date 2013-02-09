#pragma once
class Engine;

class State
{
public:
	State(void);
	virtual ~State(void);

	virtual void Initialize(Engine *rObjEngine);
	virtual void Cleanup(void);
	virtual void Pause(void);
	virtual void Resume(void);
	virtual void Update(void);
	virtual void Drow(void);
};