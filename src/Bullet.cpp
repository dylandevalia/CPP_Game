#include "Bullet.h"

#define SPEED 7
#define LIFE_SPAN 75

Bullet::Bullet(GameEngine* pEngine, int xpos, int ypos, int xdir, int ydir)
	: Entity(pEngine, false, xpos, ypos, 30, 30, 1),
	m_xdir(xdir), m_ydir(ydir),
	m_speed(SPEED + (rand() % 3) - 1),
	m_lifeSpan(LIFE_SPAN + (rand() % 11) - 5)
{

}


Bullet::~Bullet()
{
}

void Bullet::Draw() {
	GetEngine()->DrawScreenOval(
		// Top Left
		m_iCurrentScreenX,
		m_iCurrentScreenY,
		// Bottom Right
		m_iCurrentScreenX + m_iDrawWidth - 1,
		m_iCurrentScreenY + m_iDrawHeight - 1,
		// Colour
		0xffc107
	);

	StoreLastScreenPositionForUndraw();
}

void Bullet::DoUpdate(int iCurrentTime) {
	if (--m_lifeSpan <= 0) {
		deleteSelf();
		return;
	}

	m_iCurrentScreenX += m_xdir * m_speed;
	m_iCurrentScreenY += m_ydir * m_speed;

	// collisions
	if (!checkBounds()) {
		deleteSelf();
		return;
	}

	// Check for collision detection
	DisplayableObject* pob = nullptr;
	for (int index = 0; index < GetEngine()->GetLengthOfObjectArray(); index++) {
		pob = (DisplayableObject*)GetEngine()->GetDisplayableObject(index);
		if (pob == this)
			continue;

		// If an entity
		if (Entity* e = dynamic_cast<Entity*>(pob)) {
			Entity* entity = (Entity*)pob;

			// Calculate distance between objects (from centre)
			int xdiff = GetXCentre() - entity->GetXCentre();
			if (xdiff < 0) xdiff = -xdiff;
			int ydiff = GetYCentre() - entity->GetYCentre();
			if (ydiff < 0) ydiff = -ydiff;

			// Calculate size of objects
			int wdiff = (m_iDrawWidth / 2) - (entity->GetWidth() / 2);
			if (wdiff < 0) wdiff = -wdiff;
			int hdiff = (m_iDrawHeight / 2) - (entity->GetHeight() / 2);
			if (hdiff < 0) hdiff = -hdiff;

			// Compare to see if distance is less than size
			if ((xdiff*xdiff + ydiff*ydiff) < (wdiff*wdiff + hdiff*hdiff)) {
				entity->dealDamage(1);
				deleteSelf();
				RedrawObjects();
			}
		}
	}

	RedrawObjects();
}