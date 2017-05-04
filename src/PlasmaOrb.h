#pragma once
#include "header.h"
#include "templates.h"

#include "DisplayableObject.h"

class PlasmaOrb :
	public DisplayableObject
{
public:
	PlasmaOrb(BaseEngine*, int, int, int);
	~PlasmaOrb();

	void Draw();
	void DoUpdate(int);

private:
	int m_iDirX, m_iDirY;
};

