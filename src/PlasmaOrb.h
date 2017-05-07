#pragma once
#include "Entity.h"

class PlasmaOrb :
	public Entity
{
public:
	PlasmaOrb(GameEngine*, int, int, int);
	~PlasmaOrb();

	void Draw();
	void DoUpdate(int);

	void constrainInBounds();

private:
	int m_iDirX, m_iDirY;
};

