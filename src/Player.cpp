#include "Player.h"
#include "HomingBullet.h"
#include "Hostile.h"

#define SHOT_DELAY 20

Player::Player(GameEngine* pEngine, GameTileManager* pTile, bool tile, int xpos, int ypos)
	: Entity(pEngine, pTile, tile, xpos, ypos, 50, 50, 3),
	m_iSpeed(4)
{
	m_iDirX = 0;
	m_iDirY = 0;
}

Player::Player(GameEngine* pEngine, GameTileManager* pTile)
	: Entity(pEngine, pTile, false, NULL, NULL, 50, 50, 3)
{
	m_iDirX = 0;
	m_iDirY = 0;
}

Player::~Player() {
}

void Player::setPos(bool tile, int xpos, int ypos) {
	if (tile) {
		m_iCurrentScreenX = m_iPreviousScreenX = (xpos * 50) + 25 - (m_iDrawWidth / 2);
		m_iCurrentScreenY = m_iPreviousScreenY = (ypos * 50) + 25 - (m_iDrawHeight / 2);
	}
	else {
		m_iCurrentScreenX = m_iPreviousScreenX = xpos - (m_iDrawWidth / 2);
		m_iCurrentScreenY = m_iPreviousScreenY = ypos - (m_iDrawHeight / 2);
	}
}

void Player::Draw() {
	if (m_iDmg-- > 0) {
		GetEngine()->DrawScreenOval(
			// Top Left
			m_iCurrentScreenX,
			m_iCurrentScreenY,
			// Bottom Right
			m_iCurrentScreenX + m_iDrawWidth - 1,
			m_iCurrentScreenY + m_iDrawHeight - 1,
			// Colour
			0xff0000
		);
	} else if (m_iIFrame > 0) {
		GetEngine()->DrawScreenOval(
			// Top Left
			m_iCurrentScreenX,
			m_iCurrentScreenY,
			// Bottom Right
			m_iCurrentScreenX + m_iDrawWidth - 1,
			m_iCurrentScreenY + m_iDrawHeight - 1,
			// Colour
			0x00ff00
		);
	} else {
		GetEngine()->DrawScreenOval(
			// Top Left
			m_iCurrentScreenX,
			m_iCurrentScreenY,
			// Bottom Right
			m_iCurrentScreenX + m_iDrawWidth - 1,
			m_iCurrentScreenY + m_iDrawHeight - 1,
			// Colour
			0x9C27B0
		);
	}
	StoreLastScreenPositionForUndraw();
}

void Player::DoUpdate(int iCurrentTime) {
	GameEngine* pEngine = GetEngine();

	// Movement
	move(pEngine);

	// Bounds
	constrainInBounds(m_iDirX, m_iDirY);

	// Hit Detection
	if (m_iCurHealth > 0) {
		if (m_iIFrame-- < 0) {
			hit(pEngine);
		}
	} else {
		onDeath();
	}

	// Bullets
	shoot(pEngine);

	RedrawObjects();
}

void Player::onDeath() {
	deleteSelf();
}

void Player::move(GameEngine* pEngine) {
	// If shift is held move at half speed
	if (pEngine->IsKeyPressed(SDLK_LSHIFT)) {
		if (pEngine->IsKeyPressed(SDLK_a)) {
			m_iCurrentScreenX -= m_iSpeed / 2;
			m_iDirX = -m_iSpeed / 2;
		}
		else if (pEngine->IsKeyPressed(SDLK_d)) {
			m_iCurrentScreenX += m_iSpeed / 2;
			m_iDirX = m_iSpeed / 2;
		}
		else { m_iDirX = 0; }
		if (pEngine->IsKeyPressed(SDLK_w)) {
			m_iCurrentScreenY -= m_iSpeed / 2;
			m_iDirY = -m_iSpeed / 2;
		}
		else if (pEngine->IsKeyPressed(SDLK_s)) {
			m_iCurrentScreenY += m_iSpeed / 2;
			m_iDirY = m_iSpeed / 2;
		}
		else { m_iDirY = 0; }
	}
	else {
		if (pEngine->IsKeyPressed(SDLK_a)) {
			m_iCurrentScreenX -= m_iSpeed;
			m_iDirX = -m_iSpeed;
		}
		else if (pEngine->IsKeyPressed(SDLK_d)) {
			m_iCurrentScreenX += m_iSpeed;
			m_iDirX = m_iSpeed;
		}
		else { m_iDirX = 0; }
		if (pEngine->IsKeyPressed(SDLK_w)) {
			m_iCurrentScreenY -= m_iSpeed;
			m_iDirY = -m_iSpeed;
		}
		else if (pEngine->IsKeyPressed(SDLK_s)) {
			m_iCurrentScreenY += m_iSpeed;
			m_iDirY = m_iSpeed;
		}
		else { m_iDirY = 0; }
	}
}

void Player::hit(GameEngine* pEngine) {
	DisplayableObject* pob = nullptr;
	for (int i = 0; i < pEngine->GetLengthOfObjectArray(); i++) {
		pob = pEngine->GetDisplayableObject(i);
		if (pob == this) { continue; }

		if (Hostile* h = dynamic_cast<Hostile*>(pob)) {
			Hostile* e = (Hostile*)pob;

			if (checkIntersection(e)) {
				dealDamage(1);
				m_iIFrame = 60;
				return;
			}
		}
	}
}

void Player::shoot(GameEngine* pEngine) {
	if (m_iShotDelay <= 0) {
		if (pEngine->IsKeyPressed(SDLK_RIGHT)) {
			pEngine->DrawableObjectsChanged();
			pEngine->StoreObjectInArrayAtEnd(
				new Bullet(
				pEngine, m_pTile,
				m_iCurrentScreenX + m_iDrawWidth,
				m_iCurrentScreenY + (m_iDrawHeight / 2),
				1, 0
				)
				);
			pEngine->SetObjectVisibility(true);
			m_iShotDelay = SHOT_DELAY;
		}
		else if (pEngine->IsKeyPressed(SDLK_LEFT)) {
			pEngine->DrawableObjectsChanged();
			pEngine->StoreObjectInArrayAtEnd(
				new Bullet(
				pEngine, m_pTile,
				m_iCurrentScreenX,
				m_iCurrentScreenY + (m_iDrawHeight / 2),
				-1, 0
				)
				);
			pEngine->SetObjectVisibility(true);
			m_iShotDelay = SHOT_DELAY;
		}
		else if (pEngine->IsKeyPressed(SDLK_UP)) {
			pEngine->DrawableObjectsChanged();
			pEngine->StoreObjectInArrayAtEnd(
				new Bullet(
				pEngine, m_pTile,
				m_iCurrentScreenX + (m_iDrawWidth / 2),
				m_iCurrentScreenY,
				0, -1
				)
				);
			pEngine->SetObjectVisibility(true);
			m_iShotDelay = SHOT_DELAY;
		}
		else if (pEngine->IsKeyPressed(SDLK_DOWN)) {
			pEngine->DrawableObjectsChanged();
			pEngine->StoreObjectInArrayAtEnd(
				new Bullet(
				pEngine, m_pTile,
				m_iCurrentScreenX + (m_iDrawWidth / 2),
				m_iCurrentScreenY + m_iDrawHeight,
				0, 1
				)
				);
			pEngine->SetObjectVisibility(true);
			m_iShotDelay = SHOT_DELAY;
		}
	}
	else {
		m_iShotDelay--;
	}
}