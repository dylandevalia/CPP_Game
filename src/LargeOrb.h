#pragma once
#include "PlasmaOrb.h"
class LargeOrb :
	public PlasmaOrb {
public:
	LargeOrb(GameEngine*, int, int);
	~LargeOrb();
	
	void Draw();
	void onDeath();
};
