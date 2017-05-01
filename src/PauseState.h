#pragma once

#include "header.h"
#include "templates.h"

#include "GameEngine.h"

#include "Enums.h"

#include "State.h"
#include "StateManager.h"

class PauseState
	: public State {
private:
	GameEngine* m_pGame;
	StateManager* m_pStateManager;

public:
	PauseState(GameEngine*, StateManager*);
	virtual ~PauseState();

	virtual void setup();
	virtual void update();
	virtual void draw();

	/* Events */
	virtual void keyDown(int);
	virtual void keyUp(int);
	virtual void mouseMoved(int, int);
	virtual void mouseDown(int, int, int);
	virtual void mouseUp(int, int, int);
private:

};