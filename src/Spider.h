#pragma once
#include "Hostile.h"
class Spider :
	public Hostile {
public:
	Spider(GameEngine*, int, int);
	~Spider();

	void Draw();
	void DoUpdate(int);
};

