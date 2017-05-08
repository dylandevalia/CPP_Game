#pragma once
#include "Entity.h"

class PlasmaOrb :
	public Entity
{
public:
	PlasmaOrb(GameEngine*, bool, int xpos, int ypos, int speed, int size, int health);
	~PlasmaOrb();

	void Draw();
	void DoUpdate(int);

	virtual void onDeath();

	void constrainInBounds();

private:
	int m_iDirX, m_iDirY;
};

