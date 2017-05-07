#include "PlasmaOrb.h"
#include "Utility.h"

PlasmaOrb::PlasmaOrb(GameEngine* pEngine, int xpos, int ypos, int speed)
	: Entity(pEngine, true, xpos, ypos, 150, 150, 5)
{
	m_iDirX = speed * Utility::map(rand() % 2, 0, 1, -1, 1);
	m_iDirY = speed * Utility::map(rand() % 2, 0, 1, -1, 1);

	//SetVisible(true);
}


PlasmaOrb::~PlasmaOrb()
{
}

void PlasmaOrb::Draw() {
	if (m_bCurDamaged) {
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
		m_bCurDamaged = false;
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
	// printf("Update");
	m_iCurrentScreenX += m_iDirX;
	m_iCurrentScreenY += m_iDirY;

	constrainInBounds();

	RedrawObjects();
}

void PlasmaOrb::constrainInBounds() {
	if (m_iCurrentScreenX <= 50 || m_iCurrentScreenX >= GetEngine()->GetScreenWidth() - m_iDrawWidth - 50) {
		m_iDirX *= -1;
	}
	if (m_iCurrentScreenY <= 50 || m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - m_iDrawHeight - 50) {
		m_iDirY *= -1;
	}
}