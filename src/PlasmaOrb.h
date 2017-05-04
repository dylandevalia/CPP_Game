#pragma once
#include "header.h"
#include "templates.h"

#include "DisplayableObject.h"

class PlasmaOrb :
	public DisplayableObject
{
public:
	PlasmaOrb(BaseEngine*);
	~PlasmaOrb();

	void Draw();
	void update();

private:
	int m_iDirX, m_iDirY;
};

