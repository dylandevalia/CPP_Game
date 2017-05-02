#include "PlayState.h"

#include <iostream>

using namespace std;

/**
State - Play state
*/

/**
Constructor

@param pGame         Pointer to the current engine
@param pStateManager Pointer to the state manager
*/
PlayState::PlayState(GameEngine* pGame, StateManager* pStateManager)
	: m_pGame(pGame), m_pStateManager(pStateManager) {

}

PlayState::~PlayState() {

}

/**  */
void PlayState::setup() {
	cout << "State - PLAY" << endl;
}

void PlayState::update() {

}

void PlayState::draw() {
	m_pGame->FillBackground(0xDCEDC8);
	m_pGame->Redraw(true);
}

/* ------ */
/* Events */
/* ------ */

void PlayState::keyDown(int iKeyCode) {
	switch (iKeyCode) {
		case SDLK_SPACE:
			m_pStateManager->initState(GameState::PAUSE);
			m_pStateManager->setState(GameState::PAUSE);
			break;
		case SDLK_ESCAPE:
			m_pStateManager->initState(GameState::MENU);
			m_pStateManager->setState(GameState::MENU);
			break;
	}
}

void PlayState::keyUp(int iKeyCode) {

}

void PlayState::mouseMoved(int iX, int iY) {

}

void PlayState::mouseDown(int iButton, int iX, int iY) {

}

void PlayState::mouseUp(int iButton, int iX, int iY) {

}

/* -------- */
/* Overides */
/* -------- */

int PlayState::initialiseObjects() {
	return 0;
}

void PlayState::setupBackgroundBuffer() {

}

void PlayState::drawStrings() {

}


