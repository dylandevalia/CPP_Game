#pragma once
#include "TileManager.h"
#include "BaseEngine.h"
#include "JPGImage.h"

class GameTileManager :
	public TileManager {
public:
	GameTileManager(int, int);
	~GameTileManager();

	void DrawTileAt(BaseEngine*, SDL_Surface*, int, int, int, int) const;

	void SetAllValues(int);

protected:
	ImageData m_sSprite;
};

