#pragma once

#include "header.h"
#include "templates.h"

class GameState
{

public:


	virtual void setup();
	virtual void update();
	virtual void draw();
};

