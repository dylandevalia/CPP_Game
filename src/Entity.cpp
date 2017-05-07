#include "Entity.h"


Entity::Entity(GameEngine* pEngine, bool tile, int xpos, int ypos, int width, int height, int maxHealth)
	: DisplayableObject(pEngine)
{
	m_iCurHealth = m_iMaxHealth = maxHealth;

	if (tile) {
		m_iCurrentScreenX = m_iPreviousScreenX = (xpos * 50) + 25 - (width / 2);
		m_iCurrentScreenY = m_iPreviousScreenY = (ypos * 50) + 25 - (height / 2);
	} else {
		m_iCurrentScreenX = m_iPreviousScreenX = xpos - (width / 2);
		m_iCurrentScreenY = m_iPreviousScreenY = ypos - (height / 2);
	}

	m_iStartDrawPosX = m_iStartDrawPosY = 0;

	m_iDrawWidth = width;
	m_iDrawHeight = height;
}


Entity::~Entity() {
}

void Entity::constrainInBounds() {
	GameEngine* pEngine = GetEngine();
	if (m_iCurrentScreenX <= 50) {
		m_iCurrentScreenX = 50;
	}
	if (m_iCurrentScreenX >= pEngine->GetScreenWidth() - m_iDrawWidth - 50) {
		m_iCurrentScreenX = pEngine->GetScreenWidth() - m_iDrawWidth - 50;
	}
	if (m_iCurrentScreenY <= 50) {
		m_iCurrentScreenY = 50;
	}
	if (m_iCurrentScreenY >= pEngine->GetScreenHeight() - m_iDrawHeight - 50) {
		m_iCurrentScreenY = pEngine->GetScreenHeight() - m_iDrawHeight - 50;
	}
}

bool Entity::checkBounds() {
	if (m_iCurrentScreenX <= 50 || m_iCurrentScreenX >= GetEngine()->GetScreenWidth() - m_iDrawWidth - 50) {
		return false;
	}
	if (m_iCurrentScreenY <= 50 || m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - m_iDrawHeight - 50) {
		return false;
	}
	return true;
}

void Entity::deleteSelf() {
	int index = GetEngine()->GetIndexOfObjectFromArray(this);
	GetEngine()->RemoveObjectFromArray(index);
	GetEngine()->Redraw(true);
}
