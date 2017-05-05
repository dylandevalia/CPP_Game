#pragma once

#include "header.h"
#include "templates.h"

#include "Enums.h"

#include "GameEngine.h"
#include "StateManager.h"
#include "GameTileManager.h"

class Game
	: public GameEngine {

public:
	Game* m_pGame;
	StateManager m_GSM;
	GameTileManager m_GTM;

public:
	Game();
	~Game();

	int MainLoop(void);

	// Events

	void KeyDown(int iKeyCode) { m_GSM.keyDown(iKeyCode); }
	void KeyUp(int iKeyCode) { m_GSM.keyUp(iKeyCode); }
	void MouseMoved(int iX, int iY) { m_GSM.mouseMoved(iX, iY); }
	void MouseDown(int iButton, int iX, int iY) { m_GSM.mouseDown(iButton, iX, iY); }
	void MouseUp(int iButton, int iX, int iY) { m_GSM.mouseUp(iButton, iX, iY); }

	// Overrides

	int InitialiseObjects() { return m_GSM.initialiseObjects(); }
	void SetupBackgroundBuffer() { m_GSM.setupBackgroundBuffer(); }
	void DrawStrings() { m_GSM.drawStrings(); }
};