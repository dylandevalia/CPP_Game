#pragma once
#include "TileManager.h"
#include "BaseEngine.h"
#include "JPGImage.h"

class GameTileManager :
	public TileManager {
public:
	GameTileManager(int, int);
	~GameTileManager();

	/* Call to draw a tile at index using its value */
	void DrawTileAt(BaseEngine* pEngine,
		SDL_Surface* pSurface,
		int iMapX, int iMapY,
		int iStartPositionScreenX, int iStartPositionScreenY
	) const;

	/* Sets all values */
	void SetAllValues(int iValue);

protected:
	ImageData m_sSprite;
};

