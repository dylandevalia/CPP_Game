#include "SmallOrb.h"


SmallOrb::SmallOrb(GameEngine* pEngine, int xpos, int ypos)
	: PlasmaOrb(pEngine, false, xpos, ypos, 2, 50, 2)
{
}


SmallOrb::~SmallOrb() {
}

void SmallOrb::onDeath() {

}