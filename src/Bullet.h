#pragma once
#include "Entity.h"
#include "JPGImage.h"

class Bullet : public Entity {
protected:
	int m_xdir, m_ydir;
	double m_speed;
	int m_lifeSpan;

	ImageData m_sprite;

public:
	Bullet(GameEngine*, GameTileManager*, int, int, int, int);
	~Bullet();

	void Draw();
	void DoUpdate(int);
	void checkCollision();
	void onDeath();
};
