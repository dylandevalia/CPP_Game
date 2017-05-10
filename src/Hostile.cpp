#include "Hostile.h"


Hostile::Hostile(GameEngine* pEngine, GameTileManager* pTile, bool tile, int xpos, int ypos, int width, int height, int maxHealth)
	: Entity(pEngine, pTile, tile, xpos, ypos, width, height, maxHealth)
{
}


Hostile::~Hostile() {
}
