#pragma once
#include "Hostile.h"
class Spider :
	public Hostile {
public:
	Spider(GameEngine*, GameTileManager*, bool, int, int);
	~Spider();

	void Draw();
	void DoUpdate(int);
};

