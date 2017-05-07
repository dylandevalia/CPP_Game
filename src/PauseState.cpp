#include "PauseState.h"

#include <iostream>

using namespace std;

/**
State - Main menu
*/

PauseState::PauseState(GameEngine* pGame, StateManager* pStateManager, GameTileManager* pTile)
	: m_pGame(pGame), m_pStateManager(pStateManager), m_pTile(pTile)
{

}

PauseState::~PauseState() {

}

void PauseState::init() {

}

void PauseState::setup() {
	printf("State - PAUSE\n");

	m_pGame->ShouldObjectsUpdate(false);
	m_pGame->SetObjectVisibility(false);
	m_pGame->DrawObjects();
	m_pGame->SetupBackgroundBuffer();
	m_pGame->Redraw(true);
}

void PauseState::update() {

}

void PauseState::draw() {
	
	//m_pGame->Redraw(true);
}


/* ------ */
/* Events */
/* ------ */

void PauseState::keyDown(int iKeyCode) {
	//m_pStateManager->initState(GameState::PLAY);
	m_pStateManager->setState(GameState::PLAY);
}

void PauseState::keyUp(int iKeyCode) {

}

void PauseState::mouseMoved(int iX, int iY) {

}

void PauseState::mouseDown(int iButton, int iX, int iY) {
	m_pGame->Redraw(true);
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
	m_pGame->FillBackground(0xEF9A9A);
}

void PauseState::drawStrings() {
	m_pGame->DrawScreenString(
		rand() % (m_pGame->GetScreenWidth() - 100) + 50,
		rand() % (m_pGame->GetScreenHeight() - 100) + 50,
		"Paused",
		0x000000,
		NULL
	);
}
