#include "PlasmaOrb.h"

PlasmaOrb::PlasmaOrb(BaseEngine* pEngine)
	: DisplayableObject(pEngine)
{
	m_iCurrentScreenX = m_iCurrentScreenY = 100;
	m_iPreviousScreenX = m_iPreviousScreenY = 100;

	m_iStartDrawPosX = m_iStartDrawPosY = 0;

	m_iDrawWidth = 100;
	m_iDrawHeight = 50;

	SetVisible(true);
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