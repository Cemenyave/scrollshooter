#include "precomp.h"
#include "DebugTool.h"
#include <sstream>


DebugTool::DebugTool():
	logStack(), 
	consoleFont(),
	consoleBottom(0),
	lineHeight(0),
	displayControl(),
	fps(0),
	display(false)
{
	Engine &ObjEngine = Engine::GetEngine();
	display = false;
	lineHeight = 14;
	consoleFont = CL_Font(ObjEngine.graphicContext, "consolas", lineHeight);
	consoleBottom = ObjEngine.windowHeight - 20;
	displayControl = ObjEngine.keyboard.sig_key_down().connect(this, &DebugTool::TildaListener);
}

DebugTool::~DebugTool(void){
}

void DebugTool::Log(CL_String Message){
	PushLogString(new CL_String(Message));
}

void DebugTool::PushLogString(CL_String * rString){
	logStack.push_front(StringPtr(rString));
	if(logStack.size() > 10){
		logStack.pop_back();
	}
}

void DebugTool::Update(void){
	Engine &ObjEngine = Engine::GetEngine();
	fps = ObjEngine.fps;
	CountMemoryUsage();
}

void DebugTool::Draw(void){
	if(display){
		Engine &ObjEngine = Engine::GetEngine();
		CL_Draw::fill(ObjEngine.graphicContext, 10.0f, (float)consoleBottom, 260.0f, ObjEngine.windowHeight - 175.0f, CL_Colorf(1.0f, 1.0f, 1.0f, 0.07f));
		PrintLogStack();
		PrintFps();
		#ifdef WIN32
		PrintMemoryUsage();
		#endif
	}
}

void DebugTool::PrintLogStack(void){
	if(logStack.size() == 0){
		return;
	}
	int tab = 20;
	int line = 1;
	Engine &ObjEngine = Engine::GetEngine();
	for(StringList::iterator i = logStack.begin(); i != logStack.end(); i++){
		consoleFont.draw_text(ObjEngine.graphicContext, tab, consoleBottom - line++ * lineHeight, (*i)->c_str());
	}
}

void DebugTool::PrintFps(void){
	std::stringstream stream;
	stream << fps;
	Engine &ObjEngine = Engine::GetEngine();
	consoleFont.draw_text(ObjEngine.graphicContext, 10, 10, CL_String(stream.str()));
}

void DebugTool::TildaListener(const CL_InputEvent &event, const CL_InputState &state){
	if(event.str == "`"){
		display = display ? false : true;
	}
}

#ifdef WIN32
void DebugTool::CountMemoryUsage(void){
	if(GetProcessMemoryInfo(GetCurrentProcess(), &ramData, sizeof(PROCESS_MEMORY_COUNTERS))){
		memoryUsage = (float)(ramData.WorkingSetSize) /1024.0f / 1024.0f;
	}else{
		memoryUsage = (float)GetLastError();
	}
}

void DebugTool::PrintMemoryUsage(void){
	std::stringstream stream;
	stream << memoryUsage;
	Engine &ObjEngine = Engine::GetEngine();
	consoleFont.draw_text(ObjEngine.graphicContext, 10, 20, CL_String(stream.str() + " MB"));
}
#endif