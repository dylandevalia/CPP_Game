#include "Entity.h"
#include "Utility.h"

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

	int x = m_iPreviousScreenX;
	int y = m_iPreviousScreenY;

	if (!isInBounds(x + xdir, y)) {
		while (isInBounds(x + Utility::sign(xdir), y)) {
			x += Utility::sign(xdir);
		}
	}

	if (!isInBounds(x, y + ydir)) {
		while (isInBounds(x, y + Utility::sign(ydir))) {
			y += Utility::sign(ydir);
		}
	}

	m_iCurrentScreenX = x;
	m_iCurrentScreenY = y;
}

/* Checks if the entity is on safe tiles */
bool Entity::isInBounds() {
	return isInBounds(m_iCurrentScreenX,                    m_iCurrentScreenY)                 // left  up
		&& isInBounds(m_iCurrentScreenX,                    m_iCurrentScreenY + m_iDrawHeight - 1) // left  down
		&& isInBounds(m_iCurrentScreenX + m_iDrawWidth - 1, m_iCurrentScreenY)                 // right up
		&& isInBounds(m_iCurrentScreenX + m_iDrawWidth - 1, m_iCurrentScreenY + m_iDrawHeight - 1) // right down
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
