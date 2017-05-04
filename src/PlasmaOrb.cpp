#include "PlasmaOrb.h"

PlasmaOrb::PlasmaOrb(BaseEngine* pEngine, int xpos, int ypos, int speed)
	: DisplayableObject(pEngine)
{
	m_iCurrentScreenX = m_iCurrentScreenY = xpos;
	m_iPreviousScreenX = m_iPreviousScreenY = ypos;

	m_iStartDrawPosX = m_iStartDrawPosY = 0;

	m_iDrawWidth = 50;
	m_iDrawHeight = 50;

	m_iDirX = m_iDirY = speed;

	SetVisible(true);
}


PlasmaOrb::~PlasmaOrb()
{
}

void PlasmaOrb::Draw() {
	//printf("Draw\n");
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

	if (m_iCurrentScreenX <= 0 || m_iCurrentScreenX >= GetEngine()->GetScreenWidth() - m_iDrawWidth) {
		m_iDirX *= -1;
	}
	if (m_iCurrentScreenY <= 0 || m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - m_iDrawHeight) {
		m_iDirY *= -1;
	}

	RedrawObjects();
}