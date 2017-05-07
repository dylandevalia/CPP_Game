#include "Player.h"


Player::Player(BaseEngine* pEngine, int xpos, int ypos)
	: Entity(pEngine, xpos, ypos, 50, 50, 3),
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
	if (GetEngine()->IsKeyPressed(SDLK_LSHIFT)) {
		if (GetEngine()->IsKeyPressed(SDLK_a)) {
			m_iCurrentScreenX -= m_iSpeed / 2;
		} else if (GetEngine()->IsKeyPressed(SDLK_d)) {
			m_iCurrentScreenX += m_iSpeed / 2;
		}
		if (GetEngine()->IsKeyPressed(SDLK_w)) {
			m_iCurrentScreenY -= m_iSpeed / 2;
		} else if (GetEngine()->IsKeyPressed(SDLK_s)) {
			m_iCurrentScreenY += m_iSpeed / 2;
		}
	} else {
		if (GetEngine()->IsKeyPressed(SDLK_a)) {
			m_iCurrentScreenX -= m_iSpeed;
		} else if (GetEngine()->IsKeyPressed(SDLK_d)) {
			m_iCurrentScreenX += m_iSpeed;
		}
		if (GetEngine()->IsKeyPressed(SDLK_w)) {
			m_iCurrentScreenY -= m_iSpeed;
		} else if (GetEngine()->IsKeyPressed(SDLK_s)) {
			m_iCurrentScreenY += m_iSpeed;
		}
	}

	// Bounds
	if (m_iCurrentScreenX <= 50) {
		m_iCurrentScreenX = 50;
	}
	if (m_iCurrentScreenX >= GetEngine()->GetScreenWidth() - m_iDrawWidth - 50) {
		m_iCurrentScreenX = GetEngine()->GetScreenWidth() - m_iDrawWidth - 50;
	}
	if (m_iCurrentScreenY <= 50) {
		m_iCurrentScreenY = 50;
	}
	if (m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - m_iDrawHeight - 50) {
		m_iCurrentScreenY = GetEngine()->GetScreenHeight() - m_iDrawHeight - 50;
	}
}