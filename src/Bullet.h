#pragma once
#include "Entity.h"
#include "JPGImage.h"

class Bullet : public Entity {
protected:
	/* Direction vector */
	int m_xdir, m_ydir;
	/* Speed */
	double m_speed;
	/* Lifespan */
	int m_lifeSpan;

public:
	Bullet(GameEngine*, GameTileManager*, int, int, int, int);
	~Bullet();

	/* Used to draw object */
	void Draw();
	/* Called to update the object */
	void DoUpdate(int);
	/* Checks if the entity hits a hostile entity */
	void checkCollision();
	/* Called on entity death */
	void onDeath();
};
