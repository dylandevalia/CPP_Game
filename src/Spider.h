#pragma once
#include "Hostile.h"
class Spider :
	public Hostile {
public:
	Spider(GameEngine*, GameTileManager*, bool, int, int);
	~Spider();


	/* Used to draw object */
	void Draw();
	/* Called to update the object */
	void DoUpdate(int);
	/* Called on entity death */
	void onDeath();

	/* Moves the spider in a random direction */
	void moveRandomly();
	/* Moves the spider in the direction of the player */
	void moveTowardsPlayer();

protected:
	/* States */
	int m_iState, m_iWalk = 0, m_iIdle = 0;
};

