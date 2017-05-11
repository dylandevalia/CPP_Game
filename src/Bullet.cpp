#include "Bullet.h"
#include "Player.h"
#include "Hostile.h"

#define SPEED 10
#define LIFE_SPAN 75

Bullet::Bullet(GameEngine* pEngine, GameTileManager* pTile, int xpos, int ypos, int xdir, int ydir)
	: Entity(pEngine, pTile, false, xpos, ypos, 30, 30, 1),
	m_xdir(xdir), m_ydir(ydir),
	m_speed(SPEED + (rand() % 3) - 1),
	m_lifeSpan(LIFE_SPAN + (rand() % 11) - 5)
{
}

Bullet::~Bullet()
{
}

void Bullet::Draw() {
	if (m_xdir == 1) { // Right
		m_sSprite.FlexibleRenderImageWithMask(
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
		m_sSprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			50, 50,                                // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			30, 30,                                        // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	} else if (m_ydir == 1) { // Down
		m_sSprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			50, 0,                                 // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			30, 30,                                        // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	} else if (m_ydir == -1) { // Up
		m_sSprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			0, 50,                                 // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			30, 30,                                        // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	}

	StoreLastScreenPositionForUndraw();
}

void Bullet::DoUpdate(int iCurrentTime) {
	if (--m_lifeSpan <= 0) {
		onDeath();
		return;
	}

	m_iCurrentScreenX += m_xdir * m_speed;
	m_iCurrentScreenY += m_ydir * m_speed;

	// collisions
	if (!isInBounds()) {
		onDeath();
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
				onDeath();
				RedrawObjects();
				return;
			}
		}
	}
}

#include <math.h>
#include "Utility.h"

void Bullet::onDeath() {
	double xarray[10], yarray[10];

	for (int i = 0; i < 10; i++) {
		int r = Utility::randBetween(5, 15);
		xarray[i] = GetXCentre() + r * cos((MY_PI / 5) * i);
		yarray[i] = GetYCentre() + r * sin((MY_PI / 5) * i);
	}

	GetEngine()->DrawBackgroundPolygon(10, xarray, yarray, 0xB5D195);
	deleteSelf();
}