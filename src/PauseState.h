#pragma once

#include "header.h"
#include "templates.h"

#include "GameEngine.h"
#include "GameTileManager.h"

#include "Enums.h"

#include "State.h"
#include "StateManager.h"

class PauseState
	: public State {
private:
	GameEngine* m_pGame;
	StateManager* m_pStateManager;
	GameTileManager* m_pTile;

public:
	PauseState(GameEngine*, StateManager*, GameTileManager*);
	~PauseState();

	void init();
	void setup();
	void update();
	void draw();

	// Events 

	void keyDown(int);
	void keyUp(int);
	void mouseMoved(int, int);
	void mouseDown(int, int, int);
	void mouseUp(int, int, int);

	// Overides

	int initialiseObjects();
	void setupBackgroundBuffer();
	void drawStrings();

private:

};