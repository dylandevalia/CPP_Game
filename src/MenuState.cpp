#include "MenuState.h"

#include "PlasmaOrb.h"

#include <iostream>

using namespace std;

/**
State - Main menu
*/

MenuState::MenuState(GameEngine* pGame, StateManager* pStateManager, GameTileManager* pTile)
	: m_pGame(pGame), m_pStateManager(pStateManager), m_pTile(pTile)
{

}

MenuState::~MenuState() {

}

void MenuState::init() {
	m_sBackground.LoadImage("background.jpg");
	m_pGame->ShouldObjectsUpdate(false);
	m_pGame->InitialiseObjects();
}

void MenuState::setup() {
	printf("State - MENU\n");

	m_pStateManager->unloadState(GameState::PLAY);
	m_pStateManager->unloadState(GameState::PAUSE);

	m_pTile->SetAllValues(0);

	m_pGame->InitialiseObjects();
	m_pGame->SetupBackgroundBuffer();
	m_pGame->Redraw(true);
}

void MenuState::update() {

}

void MenuState::draw() {
	//setupBackgroundBuffer();
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
	m_sBackground.RenderImage(m_pGame->GetBackground(), 0, 0, (-iX / 3) - 450, (-iY / 3) - 250, 1500, 938);
	m_pGame->Redraw(true);
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

	return 0;
}

void MenuState::setupBackgroundBuffer() {
	m_pGame->FillBackground(0x81D4FA);
	m_sBackground.RenderImage(m_pGame->GetBackground(), 0, 0, -500, -300, 2880, 1800);
}

void MenuState::drawStrings() {

}