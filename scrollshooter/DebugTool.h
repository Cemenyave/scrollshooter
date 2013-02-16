#pragma once
#include "Engine.h"
#include <sstream>
#include <list>

class DebugTool
{
	typedef std::shared_ptr<CL_String> StringPtr;
	typedef std::list<StringPtr> StringList;
	StringList LogStack; 
	CL_Font mConsoleFont;

	int mConsoleBottom;
	int mLineHeight;

	void HandleConsoleStack(void) const;
	void PushLogString(CL_String * rString);
	void PrintLogStack(Engine * rObjEngine);
	void PrintFps(Engine * rObjEngine);
public:
	DebugTool(Engine *rObjEngine);
	~DebugTool(void);
	
	int fps;
	bool mDisplay;

	template<typename _Type>
	void Log(_Type const Message){
		std::stringstream msg;
		msg << Message;
		PushLogString(new CL_String(msg.str()));
		msg.clear();
	}
	void Log(CL_String Message);
	void Update(Engine * rObjEngine);
	void Draw(Engine * rObjEngine);
	void TildaListener(const CL_InputEvent &event, const CL_InputState &state);
};

