#pragma once
#include "PlasmaOrb.h"
class SmallOrb :
	public PlasmaOrb {
public:
	SmallOrb(GameEngine*, int, int);
	~SmallOrb();

	void onDeath();
};

