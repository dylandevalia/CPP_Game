
#pragma once
#include "header.h"
#include "templates.h"

#include "BaseEngine.h"

#include "GameState.h"
#include "GameStateMain.h"

#include<iostream>

using namespace std;



class GameStateManager
{

public:
	GameState* state;
	BaseEngine* pGame;
	enum states{MAIN,START,PAUSE,WIN,LOSE};

private:


public:
	GameStateManager(BaseEngine* game,int newState);
	~GameStateManager();

	void setState(int newState);

	void setup(){ state->setup(); }
	void draw(){ state->draw(); }
	void update(){ state->update(); }
};

