#pragma once
#include "Hostile.h"
#include "JPGImage.h"

class PlasmaOrb :
	public Hostile
{
public:
	PlasmaOrb(GameEngine*, GameTileManager*, bool, int xpos, int ypos, int xdir, int ydir, int speed, int size, int health);
	~PlasmaOrb();

	void Draw();
	void DoUpdate(int);

	virtual void onDeath();

	void constrainInBounds();

protected:
	int m_iDirX, m_iDirY;
	ImageData m_sprite;
};

