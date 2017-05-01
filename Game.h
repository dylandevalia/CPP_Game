#pragma once

#include "header.h"
#include "templates.h"

#include "BaseEngine.h"
#include "GameStateManager.h"

class Game
	: public BaseEngine
{

public:
	Game* pGame;
	GameStateManager GSM;
	

	Game();
	~Game();

	int MainLoop(void);

	void setup(){ }
	void draw(){ }
	void update(){ }


};

