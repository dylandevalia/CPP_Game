#include "Spider.h"

Spider::Spider(GameEngine* pEngine, GameTileManager* pTile, bool tile, int xpos, int ypos)
	: Hostile(pEngine, pTile, tile, xpos, ypos, 16, 16, 2)
{
}

Spider::~Spider() {
}

void Spider::Draw() {
	if (m_iDmg-- > 0) {
		m_sSprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			100, 325,                              // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			50, 25,                                        // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	}
	else {
		m_sSprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			0, 300,                                // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			50, 50,                                        // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	}

	StoreLastScreenPositionForUndraw();
}

void Spider::DoUpdate(int iCurrentTime) {

}