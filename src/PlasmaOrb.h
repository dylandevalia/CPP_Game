#pragma once
#include "Entity.h"

class PlasmaOrb :
	public Entity
{
public:
	PlasmaOrb(BaseEngine*, int, int, int);
	~PlasmaOrb();

	void Draw();
	void DoUpdate(int);

private:
	int m_iDirX, m_iDirY;
};

