#pragma once
#include "Entity.h"
class Hostile :
	public Entity {
public:
	Hostile(GameEngine*, bool, int, int, int, int, int);
	~Hostile();
};

