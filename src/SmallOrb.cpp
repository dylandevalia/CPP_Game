#include "SmallOrb.h"


SmallOrb::SmallOrb(GameEngine* pEngine, int xpos, int ypos, int xdir, int ydir)
	: PlasmaOrb(pEngine, false, xpos, ypos, xdir, ydir, 2, 50, 2)
{
}


SmallOrb::~SmallOrb() {
}

void SmallOrb::onDeath() {

}