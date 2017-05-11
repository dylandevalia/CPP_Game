#include "PlasmaOrb.h"

PlasmaOrb::PlasmaOrb(GameEngine* pEngine, GameTileManager* pTile, bool tile, int xpos, int ypos, int xdir, int ydir, int speed, int size, int health)
	: Hostile(pEngine, pTile, tile, xpos, ypos, size, size, health)
{
	m_iDirX = speed * xdir; // speed * Utility::map(rand() % 2, 0, 1, -1, 1);
	m_iDirY = speed * ydir; // speed * Utility::map(rand() % 2, 0, 1, -1, 1);

}

PlasmaOrb::~PlasmaOrb()
{
}

/* Used to draw object */
void PlasmaOrb::Draw() {
	if (m_iDmg-- > 0) {
		GetEngine()->DrawScreenOval(
			// Top Left
			m_iCurrentScreenX,
			m_iCurrentScreenY,
			// Bottom Right
			m_iCurrentScreenX + m_iDrawWidth - 1,
			m_iCurrentScreenY + m_iDrawHeight - 1,
			// Colour
			0xFF0000
		);
		//m_bCurDamaged = false;
	}
	else {
		GetEngine()->DrawScreenOval(
			// Top Left
			m_iCurrentScreenX,
			m_iCurrentScreenY,
			// Bottom Right
			m_iCurrentScreenX + m_iDrawWidth - 1,
			m_iCurrentScreenY + m_iDrawHeight - 1,
			// Colour
			0x00BCD4
		);
	}

	StoreLastScreenPositionForUndraw();
}

/* Called to update the object */
void PlasmaOrb::DoUpdate(int iCurrentTime) {
	if (getHealth() > 0) {
		m_iCurrentScreenX += m_iDirX;
		m_iCurrentScreenY += m_iDirY;

		constrainInBounds();

		RedrawObjects();
	} else {
		onDeath();
	}
}

/* Called on entity death -- subclasses need to overwrite this */
void PlasmaOrb::onDeath() {

}

/* Constrains the entity within the screen bounds */
void PlasmaOrb::constrainInBounds() {
	// Reverse direction
	if (m_iCurrentScreenX <= 50 || m_iCurrentScreenX >= GetEngine()->GetScreenWidth() - m_iDrawWidth - 51) {
		m_iDirX *= -1;
	}
	if (m_iCurrentScreenY <= 50 || m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - m_iDrawHeight - 51) {
		m_iDirY *= -1;
	}

	// Move back into bounds
	/*
	if (m_iCurrentScreenX <= 50) {
		m_iCurrentScreenX = 50;
	} else if (m_iCurrentScreenX >= GetEngine()->GetScreenWidth() - m_iDrawWidth - 51) {
		m_iCurrentScreenX = GetEngine()->GetScreenWidth() - m_iDrawWidth - 51;
	}
	if (m_iCurrentScreenY <= 50) {
		m_iCurrentScreenY = 50;
	} else if (m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - m_iDrawHeight - 51) {
		m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - m_iDrawHeight - 51;
	}
	*/
}