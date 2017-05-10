#pragma once
#include "Hostile.h"
class Spider :
	public Hostile {
public:
	Spider(GameEngine*, GameTileManager*, bool, int, int);
	~Spider();

	void Draw();
	void DoUpdate(int);
	void onDeath();

protected:
	int m_iState, m_iWalk = 0, m_iIdle = 0;
};

