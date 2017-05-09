#include "Bullet.h"
#include "Player.h"
#include "Hostile.h"

#define SPEED 15
#define LIFE_SPAN 75

Bullet::Bullet(GameEngine* pEngine, int xpos, int ypos, int xdir, int ydir)
	: Entity(pEngine, false, xpos, ypos, 30, 30, 1),
	m_xdir(xdir), m_ydir(ydir),
	m_speed(SPEED + (rand() % 3) - 1),
	m_lifeSpan(LIFE_SPAN + (rand() % 11) - 5)
{
	m_sprite.LoadImage("sprite_bullet-blue.png");
}

Bullet::~Bullet()
{
}

void Bullet::Draw() {
	/*
	sprite.RenderImageWithMask(
		GetEngine()->GetForeground(),
		0, 0,
		m_iCurrentScreenX, m_iCurrentScreenY,
		30, 30
	);
	*/

	if (m_xdir == 1) { // Right
		m_sprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			0, 0,                                  // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			30, 30,                                        // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	} else if (m_xdir == -1) { // Left
		m_sprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			30, 30,                                // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			30, 30,                                        // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	} else if (m_ydir == 1) { // Down
		m_sprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			30, 0,                                 // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			30, 30,                                        // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	} else if (m_ydir == -1) { // Up
		m_sprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			0, 30,                                 // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			30, 30,                                        // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	}

	/*
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
	*/

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
	checkCollision();

	RedrawObjects();
}

void Bullet::checkCollision() {
	DisplayableObject* pob = nullptr;
	for (int index = 0; index < GetEngine()->GetLengthOfObjectArray(); index++) {
		pob = GetEngine()->GetDisplayableObject(index);
		if (pob == this) { continue; }

		// If an entity
		if (Hostile* e = dynamic_cast<Hostile*>(pob)) {
			Hostile* entity = (Hostile*)pob;

			if (checkIntersection(entity)) {
				entity->dealDamage(1);
				deleteSelf();
				RedrawObjects();
			}

			/*
			// Calculate distance between objects (from centre)
			int xdiff = GetXCentre() - entity->GetXCentre();
			if (xdiff < 0) xdiff = -xdiff;
			int ydiff = GetYCentre() - entity->GetYCentre();
			if (ydiff < 0) ydiff = -ydiff;

			// Calculate size of objects
			double wdiff = (m_iDrawWidth / 2.0) - (entity->GetWidth() / 2.0);
			if (wdiff < 0) wdiff = -wdiff;
			double hdiff = (m_iDrawHeight / 2.0) - (entity->GetHeight() / 2.0);
			if (hdiff < 0) hdiff = -hdiff;

			// Compare to see if distance is less than size
			if ((xdiff*xdiff + ydiff*ydiff) <= (wdiff*wdiff + hdiff*hdiff)) {
				printf("hit\n");
				entity->dealDamage(1);
				deleteSelf();
				RedrawObjects();
			}
			printf("%d, %d, %f, %f - ", xdiff, ydiff, wdiff, hdiff);
			printf("%d, %f\n", xdiff*xdiff + ydiff*ydiff, wdiff*wdiff + hdiff*hdiff);
			*/

			/*
			if (
				abs(GetXCentre() - entity->GetXCentre()) < (GetWidth() / 2.0) + (entity->GetWidth() / 2.0) &&
				abs(GetYCentre() - entity->GetYCentre()) < (GetHeight() / 2.0) + (entity->GetHeight() / 2.0)
			) {
				//printf("hit\n");
				entity->dealDamage(1);
				deleteSelf();
				RedrawObjects();
			}
			*/
		}
	}
}