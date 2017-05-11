#pragma once
#include "PlasmaOrb.h"
class SmallOrb :
	public PlasmaOrb {
public:
	SmallOrb(GameEngine*, GameTileManager*, bool, int, int, int, int);
	SmallOrb(GameEngine*, GameTileManager*, bool, int, int);
	~SmallOrb();

	/* Used to draw object */
	void Draw();
	/* Called on entity death */
	void onDeath();
};
