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

void PlasmaOrb::onDeath() {

}

void PlasmaOrb::constrainInBounds() {
	if (m_iCurrentScreenX <= 50 || m_iCurrentScreenX >= GetEngine()->GetScreenWidth() - m_iDrawWidth - 50) {
		m_iDirX *= -1;
	}
	if (m_iCurrentScreenY <= 50 || m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - m_iDrawHeight - 50) {
		m_iDirY *= -1;
	}
}