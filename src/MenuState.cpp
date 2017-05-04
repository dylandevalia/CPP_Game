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

void MenuState::init() {
	m_pGame->InitialiseObjects();
}

void MenuState::setup() {
	cout << "State - MENU" << endl;
	m_pStateManager->unloadState(GameState::PLAY);
	m_pStateManager->unloadState(GameState::PAUSE);
	m_pGame->SetObjectVisibility(false);
}

void MenuState::update() {

}

void MenuState::draw() {
	setupBackgroundBuffer();
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

	// Undraws all the objects before destorying them
	m_pGame->UndrawObjects();

	// Destorys all existing objects
	m_pGame->DestoryOldObjects();

	return 0;
}

void MenuState::setupBackgroundBuffer() {
	m_pGame->FillBackground(0xB2EBF2);
	m_pGame->Redraw(true);
}

void MenuState::drawStrings() {

}