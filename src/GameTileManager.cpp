#include "header.h"
#include "GameTileManager.h"


GameTileManager::GameTileManager(int iTileHeight, int iTileWidth)
	: TileManager(iTileHeight, iTileWidth) {

}

GameTileManager::~GameTileManager() {

}

void GameTileManager::DrawTileAt(
	GameEngine* pEngine,
	SDL_Surface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY
	) const
{
	switch (GetValue(iMapX, iMapY)) {
		case 0:
			pEngine->DrawRectangle(
				iStartPositionScreenX,
				iStartPositionScreenY,
				iStartPositionScreenX + GetTileWidth() - 1,
				iStartPositionScreenY + GetTileHeight() - 1,
				pEngine->GetColour(GetValue(iMapX, iMapY)),
				pSurface
			);
		default:
			break;
	}
}

void GameTileManager::SetAllValues(int iValue) {
	for (int x = 0; x < m_iTileWidth; x++) {
		for (int y = 0; y < m_iTileHeight; y++) {
			SetValue(x, y, iValue);
		}
	}
}