#pragma once
#include "header.h"
#include "templates.h"

#include "GameEngine.h"

#include "State.h"
#include "Enums.h"

#include<iostream>

using namespace std;

class StateManager {

private:
	/* Array of states */
	State** m_aStates;
	/* Current state */
	State* m_pCurrrentState;

	/* Reference to engine */
	GameEngine* m_pEngine;

public:
	StateManager(GameEngine*, GameState);
	~StateManager();

	void initState(GameState);
	void setState(GameState);
	void unloadState(GameState);

	void setup() { m_pCurrrentState->setup(); }
	void draw() { m_pCurrrentState->draw(); }
	void update() { m_pCurrrentState->update(); }

	// Event 

	void keyDown(int iKeyCode) { m_pCurrrentState->keyDown(iKeyCode); }
	void keyUp(int iKeyCode) { m_pCurrrentState->keyUp(iKeyCode); }
	void mouseMoved(int iX, int iY) { m_pCurrrentState->mouseMoved(iX, iY); }
	void mouseDown(int iButton, int iX, int iY) { m_pCurrrentState->mouseDown(iButton, iX, iY); }
	void mouseUp(int iButton, int iX, int iY) { m_pCurrrentState->mouseUp(iButton, iX, iY); }

	// Overides

	int initialiseObjects() { return m_pCurrrentState->initialiseObjects(); }
	void setupBackgroundBuffer() { m_pCurrrentState->setupBackgroundBuffer(); }
	void drawStrings() { m_pCurrrentState->drawStrings(); }
};