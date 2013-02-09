#pragma once
class State
{
public:
	State(void);
	virtual ~State(void);

	virtual void Initialize(void);
	virtual void Cleanup(void);
	virtual void Pause(void);
	virtual void Resume(void);
	virtual void Update(void);
	virtual void Render(void);
};

