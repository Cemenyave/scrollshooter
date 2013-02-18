#include "precomp.h"
#include "DebugTool.h"
#include <sstream>


DebugTool::DebugTool(){
	Engine &ObjEngine = Engine::GetEngine();
	mDisplay = false;
	mLineHeight = 14;
	mConsoleFont = CL_Font(ObjEngine.mGraphicContext, "consolas", mLineHeight);
	mConsoleBottom = ObjEngine.mWindowHeight - 20;
	#ifdef WIN32
	#endif
	ObjEngine.slot_key_down.connect(ObjEngine.mKeyboard.sig_key_down(), this, &DebugTool::TildaListener);
}

DebugTool::~DebugTool(void){
}

void DebugTool::Log(CL_String Message){
	PushLogString(new CL_String(Message));
}

void DebugTool::PushLogString(CL_String * rString){
	LogStack.push_front(StringPtr(rString));
	if(LogStack.size() > 10){
		LogStack.pop_back();
	}
}

void DebugTool::Update(void){
	Engine &ObjEngine = Engine::GetEngine();
	fps = ObjEngine.fps;
	CountMemoryUsage();
}

void DebugTool::Draw(void){
	if(mDisplay){
		Engine &ObjEngine = Engine::GetEngine();
		CL_Draw::fill(ObjEngine.mGraphicContext, 10.0f, (float)mConsoleBottom, 260.0f, ObjEngine.mWindowHeight - 175.0f, CL_Colorf(1.0f, 1.0f, 1.0f, 0.07f));
		PrintLogStack();
		PrintFps();
		#ifdef WIN32
		PrintMemoryUsage();
		#endif
	}
}

void DebugTool::PrintLogStack(void){
	if(LogStack.size() == 0){
		return;
	}
	int tab = 20;
	int line = 1;
	Engine &ObjEngine = Engine::GetEngine();
	for(StringList::iterator i = LogStack.begin(); i != LogStack.end(); i++){
		mConsoleFont.draw_text(ObjEngine.mGraphicContext, tab, mConsoleBottom - line++ * mLineHeight, (*i)->c_str());
	}
}

void DebugTool::PrintFps(void){
	std::stringstream stream;
	stream << fps;
	Engine &ObjEngine = Engine::GetEngine();
	mConsoleFont.draw_text(ObjEngine.mGraphicContext, 10, 10, CL_String(stream.str()));
}

void DebugTool::TildaListener(const CL_InputEvent &event, const CL_InputState &state){
	if(event.str == "`"){
		mDisplay = mDisplay ? false : true;
	}
}

#ifdef WIN32
void DebugTool::CountMemoryUsage(void){
	if(GetProcessMemoryInfo(GetCurrentProcess(), &RamData, sizeof(PROCESS_MEMORY_COUNTERS))){
		mMemoryUsage = (float)(RamData.WorkingSetSize) /1024.0f / 1024.0f;
	}else{
		mMemoryUsage = (float)GetLastError();
	}
}

void DebugTool::PrintMemoryUsage(void){
	std::stringstream stream;
	stream << mMemoryUsage;
	Engine &ObjEngine = Engine::GetEngine();
	mConsoleFont.draw_text(ObjEngine.mGraphicContext, 10, 20, CL_String(stream.str() + " MB"));
}
#endif