#pragma once

#include "header.h"
#include "templates.h"

#include "GameEngine.h"

#include "Enums.h"

#include "State.h"
#include "StateManager.h"

class MenuState
	: public State {
public:
	GameEngine* m_pGame;
	StateManager* m_pStateManager;

	MenuState(GameEngine*, StateManager*);
	~MenuState();

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

	// Overrides
	
	int initialiseObjects();
	void setupBackgroundBuffer();
	void drawStrings();

private:

};