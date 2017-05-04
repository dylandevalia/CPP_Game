#include "MenuState.h"

#include "PlasmaOrb.h"

#include <iostream>

using namespace std;

/**
State - Main menu
*/

MenuState::MenuState(GameEngine* pGame, StateManager* pStateManager)
	: m_pGame(pGame), m_pStateManager(pStateManager) {

}

MenuState::~MenuState() {

}

void MenuState::setup() {
	cout << "State - MENU" << endl;
	m_pGame->InitialiseObjects();
}

void MenuState::update() {

}

void MenuState::draw() {
	m_pGame->FillBackground(0xB2EBF2);
	m_pGame->Redraw(true);
}

/* ------ */
/* Events */
/* ------ */

void MenuState::keyDown(int iKeyCode) {
	switch (iKeyCode) {
		case SDLK_ESCAPE:
			m_pGame->SetExitWithCode(0);
			break;
		default:
			m_pStateManager->initState(GameState::PLAY);
			m_pStateManager->setState(GameState::PLAY);
			break;
	}
}

void MenuState::keyUp(int iKeyCode) {

}

void MenuState::mouseMoved(int iX, int iY) {

}

void MenuState::mouseDown(int iButton, int iX, int iY) {

}

void MenuState::mouseUp(int iButton, int iX, int iY) {

}

/* -------- */
/* Overides */
/* -------- */

int MenuState::initialiseObjects() {
	// Informs the engine that the drawable objects have changed
	m_pGame->DrawableObjectsChanged();

	// Destorys all existing objects
	m_pGame->DestoryOldObjects();

	m_pGame->Redraw(true);

	return 0;
}

void MenuState::setupBackgroundBuffer() {

}

void MenuState::drawStrings() {

}