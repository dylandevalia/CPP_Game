#include "AdvSpider.h"


AdvSpider::AdvSpider(GameEngine* pEngine, GameTileManager* pTile, bool tile, int xpos, int ypos) 
	: Spider(pEngine, pTile, tile, xpos, ypos)
{
}

AdvSpider::~AdvSpider() {
}

/* Used to draw object */
void AdvSpider::Draw() {
	if (m_iDmg-- > 0) {
		m_sSprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			150, 325,                              // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			50, 25,                                        // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	} else {
		m_sSprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			150, 300,                              // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			50, 25,                                        // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	}

	StoreLastScreenPositionForUndraw();
}

/* Overwrites parent to call moveTowardsPlayer() */
void AdvSpider::moveRandomly() {
	moveTowardsPlayer();
}