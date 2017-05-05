#pragma once
#include "TileManager.h"
#include "GameEngine.h"

class GameTileManager :
	public TileManager {
public:
	GameTileManager(int, int);
	~GameTileManager();

	void DrawTileAt(GameEngine*, SDL_Surface*, int, int, int, int) const;

	void SetAllValues(int);
};

