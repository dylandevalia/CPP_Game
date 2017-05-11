#include "PlayState.h"

#include "Player.h"
#include "LargeOrb.h"
#include "SmallOrb.h"
#include "Spider.h"

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
PlayState::PlayState(GameEngine* pGame, StateManager* pStateManager, GameTileManager* pTile)
	: m_pGame(pGame), m_pStateManager(pStateManager), m_pTile(pTile)
{
}

PlayState::~PlayState() {

}

void PlayState::init() {
	loadLevel();
	initialiseObjects();
}

void PlayState::setup() {
	printf("State - PLAY\n");

	m_pGame->ShouldObjectsUpdate(true);
	m_pGame->SetObjectVisibility(true);
	m_pGame->SetupBackgroundBuffer();
	m_pGame->Redraw(true);
}

void PlayState::update() {
	// printf("?");
	//m_pGame->UpdateAllObjects(m_pGame->GetModifiedTime());
}

void PlayState::draw() {

}

/* ------ */
/* Events */
/* ------ */

void PlayState::keyDown(int iKeyCode) {
	switch (iKeyCode) {
		case SDLK_SPACE:
			if (!m_pStateManager->isLoaded(GameState::PAUSE)) {
				m_pStateManager->initState(GameState::PAUSE);
			}
			m_pStateManager->setState(GameState::PAUSE);
			break;
		case SDLK_ESCAPE:
			//m_pStateManager->initState(GameState::MENU);
			m_pStateManager->setState(GameState::MENU);
			break;
		case SDLK_n:
			loadLevel();
			m_pStateManager->setState(GameState::PLAY);
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
	/*
	// Informs the engine that the drawable objects have changed
	m_pGame->DrawableObjectsChanged();

	// Destorys all existing objects
	m_pGame->DestoryOldObjects();

	// Creates new array and adds new object
	m_pGame->CreateObjectArray(0);
	m_pGame->StoreObjectInArrayAtEnd(new LargeOrb(m_pGame, 10, 4));
	//m_pGame->StoreObjectInArrayAtEnd(new SmallOrb(m_pGame, 200, 200));
	m_pGame->StoreObjectInArrayAtEnd(new Player(m_pGame, 1, 1));
	//printf("%d\n", m_pGame->GetLengthOfObjectArray());
	*/

	return 0;
}

void PlayState::setupBackgroundBuffer() {
	m_pGame->FillBackground(0xC5E1A5);
	m_pTile->DrawAllTiles(m_pGame, m_pGame->GetBackground(), 0, 0, 14, 8);
}

void PlayState::drawStrings() {

}

#include <fstream>
#include <iostream>
#include <string>

void PlayState::loadLevel() {
	// Load file
	ifstream inf("levels.dat");
	if (!inf) {
		printf("Could not open file 'levels.dat'\n");
		return;
	}
	
	// Get first line
	std::string strInput;
	inf >> strInput;
	// First line specifies number of levels in file
	std::string::size_type sz;
	int noLevels = std::stoi(strInput, &sz); // Convert str -> int
	// Select random level
	int levelToLoad;
	do { levelToLoad = rand() % noLevels; } while (levelToLoad == prevLevel);
	prevLevel = levelToLoad;
	printf("Loading level - %d", levelToLoad);
	// Skip to start of chosen level
	for (int i = 1; i < (levelToLoad * 9) + 1; inf >> strInput, i++);

	// Informs the engine that the drawable objects have changed
	m_pGame->DrawableObjectsChanged();

	// Destorys all existing objects
	m_pGame->DestoryOldObjects();

	// Creates new array and adds new object
	m_pGame->CreateObjectArray(0);

	// Go through file to get level information
	printf("\n");
	for (int y = 0; y < 9; y++) {
		inf >> strInput; // Get next line
		cout << strInput << endl; // Print level to console
		for (int x = 0; x < 15; x++) {
			int value = strInput[x] - 'a';
			m_pTile->SetValue(x, y, value);
			switch (value) {
				case 4: // e: player
					m_pGame->StoreObjectInArrayAtEnd(new Player(m_pGame, m_pTile, true, x, y));
					break;
				case 5: // f: fly
					break;
				case 6: // g: spider
					m_pGame->StoreObjectInArrayAtBeginning(new Spider(m_pGame, m_pTile, true, x, y));
					break;
				case 7: // h: small orb
					m_pGame->StoreObjectInArrayAtBeginning(new SmallOrb(m_pGame, m_pTile, true, x, y));
					break;
				case 8: // i: large orb
					m_pGame->StoreObjectInArrayAtBeginning(new LargeOrb(m_pGame, m_pTile, true, x, y));
					break;
			}
		}
	}
	printf("\n");
}
