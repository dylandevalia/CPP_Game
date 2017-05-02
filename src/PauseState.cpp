#include "PauseState.h"

#include <iostream>

using namespace std;

/**
State - Main menu
*/

PauseState::PauseState(GameEngine* pGame, StateManager* pStateManager)
	: m_pGame(pGame), m_pStateManager(pStateManager) {

}

PauseState::~PauseState() {

}

void PauseState::setup() {
	cout << "State - PAUSE" << endl;
}

void PauseState::update() {

}

void PauseState::draw() {
	m_pGame->FillBackground(0xFFCDD2);
	m_pGame->Redraw(true);
}


/* ------ */
/* Events */
/* ------ */

void PauseState::keyDown(int iKeyCode) {
	m_pStateManager->initState(GameState::PLAY);
	m_pStateManager->setState(GameState::PLAY);
}

void PauseState::keyUp(int iKeyCode) {

}

void PauseState::mouseMoved(int iX, int iY) {

}

void PauseState::mouseDown(int iButton, int iX, int iY) {

}

void PauseState::mouseUp(int iButton, int iX, int iY) {

}

/* -------- */
/* Overides */
/* -------- */

int PauseState::initialiseObjects() {
	return 0;
}

void PauseState::setupBackgroundBuffer() {

}

void PauseState::drawStrings() {

}
