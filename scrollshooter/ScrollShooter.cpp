#include "precomp.h"
#include "scrollShooter.h"
#include "Engine.h"
#include <ClanLib/application.h>

int ScrollShooter::main(const std::vector<CL_String> &args)
{
	Engine Game;
	return Game.Loop();
}
 
// Create global application object, you MUST include this line or the application start-up will fail to locate your application object.
CL_ClanApplication app(&ScrollShooter::main);