#include "MenuState.h"

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
}

void MenuState::update() {

}

void MenuState::draw() {
	m_pGame->FillBackground(0xB2EBF2);
	stringdrawer();
	m_pGame->Redraw(false);
}



void MenuState::stringdrawer() {
	//cout << "a" << endl;
	//pGame->CopyBackgroundPixels(0/*X*/, 280/*Y*/, pGame->GetScreenWidth(), 40/*Height*/);
	m_pGame->DrawScreenString(100, 300, "Mine", 0x000000, m_pGame->GetFont("VT323-Regular.ttf", 24));
}



/* Events */
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
