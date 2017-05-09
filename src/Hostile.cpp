#include "Hostile.h"


Hostile::Hostile(GameEngine* pEngine, bool tile, int xpos, int ypos, int width, int height, int maxHealth) 
	: Entity(pEngine, tile, xpos, ypos, width, height, maxHealth)
{
}


Hostile::~Hostile() {
}
