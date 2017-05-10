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

	void Draw();
	void DoUpdate(int);
	Entity* findClosestEntity(int range);
	void steer();
};

