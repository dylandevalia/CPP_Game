#include "Entity.h"


Entity::Entity(BaseEngine* pEngine, int xtile, int ytile, int width, int height, int maxHealth)
	: DisplayableObject(pEngine)
{
	m_iCurHealth = m_iMaxHealth = maxHealth;

	m_iCurrentScreenX = m_iPreviousScreenX = (xtile * 50) + 25 - (width / 2);
	m_iCurrentScreenY = m_iPreviousScreenY = (ytile * 50) + 25 - (height / 2);

	m_iStartDrawPosX = m_iStartDrawPosY = 0;

	m_iDrawWidth = width;
	m_iDrawHeight = height;
}


Entity::~Entity() {
}
