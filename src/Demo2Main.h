#pragma once

#include "GameEngine.h"
#include "TileManager.h"
#include "Demo2TileManager.h"


class Demo2Main :
	public GameEngine
{
public:
	Demo2Main(void);
	~Demo2Main(void);

	void SetupBackgroundBuffer();

	int InitialiseObjects();
	void DrawStrings();
	void GameAction();
	void MouseDown( int iButton, int iX, int iY );
	void KeyDown(int iKeyCode);

private:
	Demo2TileManager m_oTiles;
};
