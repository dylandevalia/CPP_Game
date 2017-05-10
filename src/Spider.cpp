#include "Spider.h"

Spider::Spider(GameEngine* pEngine, GameTileManager* pTile, bool tile, int xpos, int ypos)
	: Hostile(pEngine, pTile, tile, xpos, ypos, 50, 25, 2),
	m_iState(0)
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
			100, 300,                              // Start coords in image
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

void Spider::DoUpdate(int iCurrentTime) {
	switch (m_iState) {
		case 0: // idle
			if (m_iIdle-- < 0) {
				m_iState = 1;
				m_iWalk = (rand() % 40) + 20;
				m_iDirX = rand() % 7 - 3;
				m_iDirY = rand() % 7 - 3;
			}
			break;
		case 1: // walk
			if (m_iWalk-- < 0) {
				m_iState = 0;
				m_iIdle = (rand() % 50) + 20;
			} else {
				m_iCurrentScreenX += m_iDirX;
				m_iCurrentScreenY += m_iDirY;
			}
			break;
	}

	constrainInBounds(m_iDirX, m_iDirY);

	if (getHealth() < 0) {
		onDeath();
	}
}

void Spider::onDeath() {
	deleteSelf();
}