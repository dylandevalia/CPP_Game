#include "Entity.h"


Entity::Entity(GameEngine* pEngine, GameTileManager* pTile, bool tile, int xpos, int ypos, int width, int height, int maxHealth)
	: DisplayableObject(pEngine), m_pTile(pTile)
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

	m_sSprite.LoadImage("spritesheet.png");
}


Entity::~Entity() {
}

/* Constrains the entity within the bounds of the screen */
void Entity::constrainInBounds(int xdir, int ydir) {
	if (isInBounds()) { return; }

	if (xdir < 0) {
		m_iCurrentScreenX = (m_pTile->GetTileXForPositionOnScreen(m_iCurrentScreenX) + 1) * 50;
	} else if (xdir > 0) {
		m_iCurrentScreenX = (m_pTile->GetTileXForPositionOnScreen(m_iCurrentScreenX) - 1) * 50 + m_iDrawWidth;
	}

	if (ydir < 0) {
		m_iCurrentScreenY = (m_pTile->GetTileYForPositionOnScreen(m_iCurrentScreenY) + 1) * 50;
	} else if (ydir > 0) {
		m_iCurrentScreenY = (m_pTile->GetTileYForPositionOnScreen(m_iCurrentScreenY) - 1) * 50 + m_iDrawHeight - 1;
	}
}

/* Checks if the entity is on safe tiles */
bool Entity::isInBounds() {
	return isInBounds(m_iCurrentScreenX,                m_iCurrentScreenY)                 // left  up
		&& isInBounds(m_iCurrentScreenX,                m_iCurrentScreenY + m_iDrawHeight) // left  down
		&& isInBounds(m_iCurrentScreenX + m_iDrawWidth, m_iCurrentScreenY)                 // right up
		&& isInBounds(m_iCurrentScreenX + m_iDrawWidth, m_iCurrentScreenY + m_iDrawHeight) // right down
	;
}

/* Checks if the given point is not on a 'solid' tile */
// If on safe tile  - return true
// If on soild tile - return false
bool Entity::isInBounds(int xpos, int ypos) {
	return (m_pTile->GetValue(m_pTile->GetTileXForPositionOnScreen(xpos), m_pTile->GetTileYForPositionOnScreen(ypos)) > 2);
}

int Entity::getDistanceBetween(Entity* target) {
	int xdiff = GetXCentre() - target->GetXCentre();
	int ydiff = GetYCentre() - target->GetYCentre();
	return xdiff*xdiff + ydiff*ydiff;
}

/* Checks if the entity is colliding with the given entity */
bool Entity::checkIntersection(Entity* target) {
	// (a.x - b.x)^2 + (a.y - b.y)^2 <= (a.r + b.r)^2

	double r = (GetWidth() / 2.0) + (target->GetWidth() / 2.0);
	
	return (getDistanceBetween(target) <= r*r);
}

/* Deletes itself from the object array */
void Entity::deleteSelf() {
	int index = GetEngine()->GetIndexOfObjectFromArray(this);
	GetEngine()->RemoveObjectFromArray(index);
	GetEngine()->Redraw(true);
}
