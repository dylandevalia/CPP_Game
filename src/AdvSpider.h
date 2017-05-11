#pragma once
#include "Spider.h"
class AdvSpider :
	public Spider {
public:
	AdvSpider(GameEngine* pEngine, GameTileManager* pTile, bool tile, int xpos, int ypos);
	~AdvSpider();

	/* Used to draw object */
	void Draw();
	/* Overwrites parent to call moveTowardsPlayer() */
	void moveRandomly();
};

