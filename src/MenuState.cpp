#include "MenuState.h"

#include "PlasmaOrb.h"

#include <fstream>
#include <iostream>

using namespace std;

/**
State - Main menu
*/

MenuState::MenuState(GameEngine* pGame, StateManager* pStateManager, GameTileManager* pTile)
	: m_pGame(pGame), m_pStateManager(pStateManager), m_pTile(pTile), m_iScore(0), m_iScoreCooldown(0)
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

	sprintf(m_str, "PRESS SPACE TO START");

	m_pGame->InitialiseObjects();
	m_pGame->SetupBackgroundBuffer();
	m_pGame->Redraw(true);
}

#include <fstream>
#include <iostream>
#include <string>

void MenuState::update() {
	if (m_iScoreCooldown < 0) {
		int maxScore;

		/* Load file - if not found create new one with initial score of 0 */
		ifstream fScore("highscore.dat");
		if (fScore) {
			// Get first line
			std::string strInput;
			fScore >> strInput;
			// First line specifies number of levels in file
			std::string::size_type sz;
			maxScore = std::stoi(strInput, &sz); // Convert str -> int
			fScore.close();
		} else {
			maxScore = 0;
		}

		/* Write new highscore to file */
		if (m_iScore > maxScore) {
			ofstream fScore("highscore.dat", std::ios::out | std::ios::trunc);
			fScore << m_iScore;
			fScore.close();
		}

		sprintf(m_str, "PRESS SPACE TO START");
		m_iScore = 0;
	} else {
		m_iScoreCooldown--;
	}
}

void MenuState::draw() {
	m_pGame->Redraw(true);
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
	m_pGame->DrawBackgroundString(200 + ((-iX / 2) + 175), 200 + ((-iY / 2) + 150), m_str, 0xFFFFFF, NULL);
}

void MenuState::mouseDown(int iButton, int iX, int iY) {
	sprintf(m_str, "%d", ++m_iScore);
	m_iScoreCooldown = 200 ;
	mouseMoved(iX, iY);
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
	m_pGame->DrawBackgroundString(200, 200, "PRESS SPACE TO START", 0xFFFFFF, NULL);
}

void MenuState::drawStrings() {

}