#pragma once
#include "Engine.h"
#include <sstream>
#include <list>
#ifdef WIN32
#include <windows.h>
#include <Psapi.h>
#endif

class DebugTool
{
	typedef std::shared_ptr<CL_String> StringPtr;
	typedef std::list<StringPtr> StringList;
	
	StringList logStack; 
	CL_Font consoleFont;
	int consoleBottom;
	int lineHeight;
	CL_Slot displayControl;
	
	void HandleConsoleStack(void) const;
	void PushLogString(CL_String * rString);
	void PrintLogStack(void);
	void PrintFps(void);

	#ifdef WIN32
	HANDLE currentProcess;
	PROCESS_MEMORY_COUNTERS ramData;
	TOKEN_PRIVILEGES tp;
	float memoryUsage;
	void CountMemoryUsage(void);
	void PrintMemoryUsage(void);
	#endif
public:
	int fps;
	bool display;

	DebugTool(void);
	~DebugTool(void);
	template<typename _Type>
	void Log(_Type const Message){
		std::stringstream msg;
		msg << Message;
		PushLogString(new CL_String(msg.str()));
		msg.clear();
	}
	void Log(CL_String Message);
	void Update(void);
	void Draw(void);
	void TildaListener(const CL_InputEvent &event, const CL_InputState &state);
};

