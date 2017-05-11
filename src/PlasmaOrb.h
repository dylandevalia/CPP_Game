#pragma once
#include "Hostile.h"
#include "JPGImage.h"

class PlasmaOrb :
	public Hostile
{
public:
	PlasmaOrb(GameEngine*, GameTileManager*, bool, int xpos, int ypos, int xdir, int ydir, int speed, int size, int health);
	~PlasmaOrb();

	/* Used to draw object */
	void Draw();
	/* Called to update the object */
	void DoUpdate(int);

	/* Called on entity death */
	virtual void onDeath();

	/* Constrains the entity within the screen bounds */
	void constrainInBounds();

protected:
	int m_iDirX, m_iDirY;
	ImageData m_sprite;
};

