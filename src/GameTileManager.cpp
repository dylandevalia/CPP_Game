#include "header.h"
#include "GameTileManager.h"


GameTileManager::GameTileManager(int iTileHeight, int iTileWidth)
	: TileManager(iTileHeight, iTileWidth) {

}

GameTileManager::~GameTileManager() {

}

void GameTileManager::DrawTileAt(
	BaseEngine* pEngine,
	SDL_Surface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY
	) const {
	switch (GetValue(iMapX, iMapY)) {
		case 0: // Black
			pEngine->DrawRectangle(
				iStartPositionScreenX,
				iStartPositionScreenY,
				iStartPositionScreenX + GetTileWidth() - 1,
				iStartPositionScreenY + GetTileHeight() - 1,
				0x000000,
				pSurface
			);
			break;
		case 1: // Walls
			pEngine->DrawRectangle(
				iStartPositionScreenX,
				iStartPositionScreenY,
				iStartPositionScreenX + GetTileWidth() - 1,
				iStartPositionScreenY + GetTileHeight() - 1,
				0xB0BEC5,
				pSurface
			);
			break;
		case 2: // Floor
			pEngine->DrawRectangle(
				iStartPositionScreenX,
				iStartPositionScreenY,
				iStartPositionScreenX + GetTileWidth() - 1,
				iStartPositionScreenY + GetTileHeight() - 1,
				0xDCEDC8,
				pSurface
				);
			break;
		case 3: // Floor alt
			pEngine->DrawRectangle(
				iStartPositionScreenX,
				iStartPositionScreenY,
				iStartPositionScreenX + GetTileWidth() - 1,
				iStartPositionScreenY + GetTileHeight() - 1,
				0xC5E1A5,
				pSurface
				);
			break;
		default:
			break;
	}
}

void GameTileManager::SetAllValues(int iValue) {
	for (int y = 0; y < m_iMapHeight; y++) {
		for (int x = 0; x < m_iMapWidth; x++) {
			SetValue(x, y, iValue);
		}
	}
}