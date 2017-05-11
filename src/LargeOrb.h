#pragma once
#include "PlasmaOrb.h"
class LargeOrb :
	public PlasmaOrb {
public:
	LargeOrb(GameEngine*, GameTileManager*, bool, int, int);
	~LargeOrb();
	
	/* Used to draw the object */
	void Draw();
	/* Called on entity death */
	void onDeath();
};
