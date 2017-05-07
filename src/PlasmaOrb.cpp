#include "PlasmaOrb.h"
#include "Utility.h"

PlasmaOrb::PlasmaOrb(BaseEngine* pEngine, int xpos, int ypos, int speed)
	: Entity(pEngine, xpos, ypos, 150, 150, 5)
{
	m_iDirX = speed * Utility::map(rand() % 2, 0, 1, -1, 1);
	m_iDirY = speed * Utility::map(rand() % 2, 0, 1, -1, 1);

	//SetVisible(true);
}


PlasmaOrb::~PlasmaOrb()
{
}

void PlasmaOrb::Draw() {
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

	StoreLastScreenPositionForUndraw();
}

void PlasmaOrb::DoUpdate(int iCurrentTime) {
	// printf("Update");
	m_iCurrentScreenX += m_iDirX;
	m_iCurrentScreenY += m_iDirY;

	if (m_iCurrentScreenX <= 50 || m_iCurrentScreenX >= GetEngine()->GetScreenWidth() - m_iDrawWidth - 50) {
		m_iDirX *= -1;
	}
	if (m_iCurrentScreenY <= 50 || m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - m_iDrawHeight - 50) {
		m_iDirY *= -1;
	}

	RedrawObjects();
}