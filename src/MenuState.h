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
	virtual ~MenuState();

	virtual void setup();
	virtual void update();
	virtual void draw();

	void stringdrawer();

	/* Events */
	virtual void keyDown(int);
	virtual void keyUp(int);
	virtual void mouseMoved(int, int);
	virtual void mouseDown(int, int, int);
	virtual void mouseUp(int, int, int);
private:

};