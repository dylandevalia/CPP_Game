#include "Player.h"
#include "HomingBullet.h"

#define SHOT_DELAY 20

Player::Player(GameEngine* pEngine, int xpos, int ypos)
	: Entity(pEngine, true, xpos, ypos, 50, 50, 3),
	m_iSpeed(4)
{

}


Player::~Player() {
}

void Player::Draw() {
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

	StoreLastScreenPositionForUndraw();
}

void Player::DoUpdate(int iCurrentTime) {
	GameEngine* pEngine = GetEngine();

	// Movement
	// If shift is held move at half speed
	if (pEngine->IsKeyPressed(SDLK_LSHIFT)) {
		if (pEngine->IsKeyPressed(SDLK_a)) {
			m_iCurrentScreenX -= m_iSpeed / 2;
		} else if (pEngine->IsKeyPressed(SDLK_d)) {
			m_iCurrentScreenX += m_iSpeed / 2;
		}
		if (pEngine->IsKeyPressed(SDLK_w)) {
			m_iCurrentScreenY -= m_iSpeed / 2;
		} else if (pEngine->IsKeyPressed(SDLK_s)) {
			m_iCurrentScreenY += m_iSpeed / 2;
		}
	} else {
		if (pEngine->IsKeyPressed(SDLK_a)) {
			m_iCurrentScreenX -= m_iSpeed;
		} else if (pEngine->IsKeyPressed(SDLK_d)) {
			m_iCurrentScreenX += m_iSpeed;
		}
		if (pEngine->IsKeyPressed(SDLK_w)) {
			m_iCurrentScreenY -= m_iSpeed;
		} else if (pEngine->IsKeyPressed(SDLK_s)) {
			m_iCurrentScreenY += m_iSpeed;
		}
	}

	// Bounds
	constrainInBounds();

	// Bullets
	if (m_iShotDelay <= 0) {
		if (pEngine->IsKeyPressed(SDLK_RIGHT)) {
			pEngine->DrawableObjectsChanged();
			pEngine->StoreObjectInArrayAtEnd(
				new Bullet(
					pEngine,
					m_iCurrentScreenX + m_iDrawWidth,
					m_iCurrentScreenY + (m_iDrawHeight / 2),
					1, 0
				)
			);
			pEngine->SetObjectVisibility(true);
			m_iShotDelay = SHOT_DELAY;
			//pEngine->Redraw(true);
		} else if (pEngine->IsKeyPressed(SDLK_LEFT)) {
			pEngine->DrawableObjectsChanged();
			pEngine->StoreObjectInArrayAtEnd(
				new Bullet(
					pEngine,
					m_iCurrentScreenX,
					m_iCurrentScreenY + (m_iDrawHeight / 2),
					-1, 0
				)
			);
			pEngine->SetObjectVisibility(true);
			m_iShotDelay = SHOT_DELAY;
			//pEngine->Redraw(true);
		} else if (pEngine->IsKeyPressed(SDLK_UP)) {
			pEngine->DrawableObjectsChanged();
			pEngine->StoreObjectInArrayAtEnd(
				new Bullet(
					pEngine,
					m_iCurrentScreenX + (m_iDrawWidth / 2),
					m_iCurrentScreenY,
					0, -1
				)
			);
			pEngine->SetObjectVisibility(true);
			m_iShotDelay = SHOT_DELAY;
			//pEngine->Redraw(true);
		} else if (pEngine->IsKeyPressed(SDLK_DOWN)) {
			pEngine->DrawableObjectsChanged();
			pEngine->StoreObjectInArrayAtEnd(
				new Bullet(
					pEngine,
					m_iCurrentScreenX + (m_iDrawWidth / 2),
					m_iCurrentScreenY + m_iDrawHeight,
					0, 1
				)
			);
			pEngine->SetObjectVisibility(true);
			m_iShotDelay = SHOT_DELAY;
			//pEngine->Redraw(true);
		}
	} else {
		m_iShotDelay--;
	}

	RedrawObjects();
}