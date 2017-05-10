#include "HomingBullet.h"
#include "Player.h"

#include <math.h>

HomingBullet::HomingBullet(GameEngine* pEngine, int xpos, int ypos, int xdir, int ydir) 
	: Bullet(pEngine, xpos, ypos, xdir, ydir),
	posx(GetXCentre() * 1.0), posy(GetYCentre() * 1.0),
	velx(xdir * m_speed * 1.0), vely(ydir * m_speed * 1.0),
	accx(0.0), accy(0.0),
	maxforce(5.0)
{
}


HomingBullet::~HomingBullet() {
}

void HomingBullet::Draw() {
	if (m_xdir == 1) { // Right
		m_sSprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			100, 0,                                // Start coords in image
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
			150, 50,                               // Start coords in image
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
			150, 0,                                 // Start coords in image
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
			100, 50,                               // Start coords in image
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

void HomingBullet::DoUpdate(int iCurrentTime) {
	if (--m_lifeSpan <= 0) {
		deleteSelf();
		return;
	}

	steer();

	// vel.add(acc)
	velx += accx;
	vely += accy;
	// vel.limit(maxforce)
	double mag = sqrt(velx*velx + vely*vely);
	velx /= mag;
	vely /= mag;
	velx *= maxforce;
	vely *= maxforce;
	// pos.add(vel)
	m_iCurrentScreenX += velx;
	m_iCurrentScreenY += vely;
	// acc.mult(0)
	accx = accy = 0;

	// collisions
	if (!checkBounds()) {
		deleteSelf();
		return;
	}

	// Check for collision detection
	checkCollision();

	RedrawObjects();
}

Entity* HomingBullet::findClosestEntity(int range) {
	int iClosest = INT_MAX;
	Entity* pClosest = nullptr;
	DisplayableObject* pob = nullptr;
	for (int i = 0; i < GetEngine()->GetLengthOfObjectArray(); i++) {
		pob = GetEngine()->GetDisplayableObject(i);
		// Continue if another bullet or the player
		if (Bullet* e = dynamic_cast<Bullet*>(pob)) { continue; }
		if (Player* e = dynamic_cast<Player*>(pob)) { continue; }

		if (Entity* e = dynamic_cast<Entity*>(pob)) {
			Entity* entity = (Entity*)pob;

			int dist = getDistanceBetween(entity);
			if (dist < range*range && dist < iClosest) {
				iClosest = dist;
				pClosest = entity;
			}
		}
	}
	return pClosest;
}

void HomingBullet::steer() {
	Entity* pClosest = findClosestEntity(150);
	if (pClosest != nullptr) {
		// desired = target - pos
		float desiredx = pClosest->GetXCentre() - GetXCentre();
		float desiredy = pClosest->GetYCentre() - GetYCentre();

		// Normalise and set magnitude to max speed
		float mag = sqrt(getDistanceBetween(pClosest) * 1.0);
		desiredx /= mag;
		desiredy /= mag;
		desiredx *= m_speed;
		desiredy *= m_speed;

		// steer = desired - vel
		float steerx = desiredx - velx;
		float steery = desiredy - vely;

		// steer.limit(maxforce)
		float magSteer = sqrt(steerx*steerx + steery*steery * 1.0);
		steerx /= mag;
		steery /= mag;
		steerx *= maxforce;
		steery *= maxforce;

		// applyforce
		// acc.add(steer)
		accx += steerx;// / pClosest->GetWidth();
		accy += steery;// / pClosest->GetWidth();
	}
}