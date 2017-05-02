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
};

