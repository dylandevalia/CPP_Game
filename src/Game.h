#pragma once

#include "header.h"
#include "templates.h"

#include "Enums.h"

#include "GameEngine.h"
#include "StateManager.h"

class Game
	: public GameEngine {

public:
	Game* m_pGame;
	StateManager m_GSM;

	Game();
	~Game();

	int MainLoop(void);

	/* Events */
	void KeyDown(int iKeyCode) { m_GSM.keyDown(iKeyCode); }
	void KeyUp(int iKeyCode) { m_GSM.keyUp(iKeyCode); }
	void MouseMoved(int iX, int iY) { m_GSM.mouseMoved(iX, iY); }
	void MouseDown(int iButton, int iX, int iY) { m_GSM.mouseDown(iButton, iX, iY); }
	void MouseUp(int iButton, int iX, int iY) { m_GSM.mouseUp(iButton, iX, iY); }
};