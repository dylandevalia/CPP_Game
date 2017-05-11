#include "Spider.h"

#include "Player.h"
#include "Utility.h"
#include <math.h>

Spider::Spider(GameEngine* pEngine, GameTileManager* pTile, bool tile, int xpos, int ypos)
	: Hostile(pEngine, pTile, tile, xpos, ypos, 50, 25, 2),
	m_iState(0)
{
	m_iDirX = m_iDirY = 0;
}

Spider::~Spider() {
}

/* Used to draw object */
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

/* Called to update the object */
void Spider::DoUpdate(int iCurrentTime) {
	switch (m_iState) {
		case 0: // idle
			if (m_iIdle-- < 0) {
				m_iState = 1;
				m_iWalk = (rand() % 30) + 20;
				if (rand() % 2 == 0) {
					moveRandomly();
				} else {
					moveTowardsPlayer();
				}
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

	if (getHealth() <= 0) {
		onDeath();
	}

	RedrawObjects();
}

/* Called on entity death */
void Spider::onDeath() {
	deleteSelf();
}

/* Moves the spider in a random direction */
void Spider::moveRandomly() {
	m_iDirX = Utility::randBetween(-3, 3);
					m_iDirY = Utility::randBetween(-3, 3);
}

/* Moves the spider in the direction of the player */
void Spider::moveTowardsPlayer() {
	Player* player;
	for (int i = 0; i < GetEngine()->GetLengthOfObjectArray(); i++) {
		DisplayableObject* pob = GetEngine()->GetDisplayableObject(i);
		if (Player* p = dynamic_cast<Player*>(pob)) {
			// player object
			player = (Player*)pob;

			// Vector from spider to player
			m_iDirX = player->GetXCentre() - GetXCentre();
			m_iDirY = player->GetYCentre() - GetYCentre();

			// normalise 
			double a = sqrt(m_iDirX*m_iDirX + m_iDirY*m_iDirY * 1.0);
			double bx = m_iDirX / a, by = m_iDirY / a;
			// magnitude by 3
			m_iDirX = bx * 3;
			m_iDirY = by * 3;

			break;
		}
	}
}