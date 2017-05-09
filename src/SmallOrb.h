#pragma once
#include "PlasmaOrb.h"
class SmallOrb :
	public PlasmaOrb {
public:
	SmallOrb(GameEngine*, int, int, int, int);
	~SmallOrb();

	void onDeath();
};

