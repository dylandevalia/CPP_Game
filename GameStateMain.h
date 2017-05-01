#pragma once

#include "header.h"
#include "templates.h"

#include "BaseEngine.h"

#include "GameState.h"

class GameStateMain
	: public GameState
{
public:
	BaseEngine* pGame;

	GameStateMain(BaseEngine* pGame);
	virtual ~GameStateMain();

	virtual void setup();
	virtual void update();
	virtual void draw();

};

