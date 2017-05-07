#pragma once
#include "Entity.h"

class Bullet : public Entity {
private:
	int m_xdir, m_ydir;
	double m_speed;
	int m_lifeSpan;

public:
	Bullet(GameEngine*, int, int, int, int);
	~Bullet();

	void Draw();
	void DoUpdate(int);
};

