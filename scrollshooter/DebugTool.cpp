#include "precomp.h"
#include "DebugTool.h"
#include <sstream>


DebugTool::DebugTool(Engine *rObjEngine){
	mDisplay = false;
	mLineHeight = 14;
	mConsoleFont = CL_Font(rObjEngine->mGraphicContext, "consolas", mLineHeight);
	mConsoleBottom = rObjEngine->mWindowHeight - 20;
	#ifdef WIN32
	#endif
	rObjEngine->slot_key_down.connect(rObjEngine->mKeyboard.sig_key_down(), this, &DebugTool::TildaListener);
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

void DebugTool::Update(Engine * rObjEngine){
	fps = rObjEngine->fps;
	CountMemoryUsage();
}

void DebugTool::Draw(Engine * rObjEngine){
	if(mDisplay){
		CL_Draw::fill(rObjEngine->mGraphicContext, 10.0f, (float)mConsoleBottom, 260.0f, rObjEngine->mWindowHeight - 175.0f, CL_Colorf(1.0f, 1.0f, 1.0f, 0.07f));
		PrintLogStack(rObjEngine);
		PrintFps(rObjEngine);
		#ifdef WIN32
		PrintMemoryUsage(rObjEngine);
		#endif
	}
}

void DebugTool::PrintLogStack(Engine * rObjEngine){
	if(LogStack.size() == 0){
		return;
	}
	int tab = 20;
	int line = 1;
	for(StringList::iterator i = LogStack.begin(); i != LogStack.end(); i++){
		mConsoleFont.draw_text(rObjEngine->mGraphicContext, tab, mConsoleBottom - line++ * mLineHeight, (*i)->c_str());
	}
}

void DebugTool::PrintFps(Engine * rObjEngine){
	std::stringstream stream;
	stream << fps;
	mConsoleFont.draw_text(rObjEngine->mGraphicContext, 10, 10, CL_String(stream.str()));
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

void DebugTool::PrintMemoryUsage(Engine * rObjEngine){
	std::stringstream stream;
	stream << mMemoryUsage;
	mConsoleFont.draw_text(rObjEngine->mGraphicContext, 10, 20, CL_String(stream.str() + " MB"));
}
#endif