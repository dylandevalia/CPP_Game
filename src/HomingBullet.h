#pragma once
#include "Bullet.h"
class HomingBullet :
	public Bullet {
protected:
	/* Position */
	double posx, posy;
	/* Velocity */
	double velx, vely;
	/* Acceleration */
	double accx, accy;

	double maxforce;

public:
	HomingBullet(GameEngine* pEngine, GameTileManager* pTile, int xpos, int ypos, int xdir, int ydir);
	~HomingBullet();

	/* Used to draw object */
	void Draw();
	/* Called to update the object */
	void DoUpdate(int);

	/* Searches through the object array to find the closet entity within a range */
	Entity* findClosestEntity(int range);
	/* Steering algorithm to move towards the nearest entity */
	void steer();
};

