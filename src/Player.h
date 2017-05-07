#pragma once
#include "Entity.h"
class Player :
	public Entity {
public:
	Player(GameEngine*, int, int);
	~Player();

	void Draw();
	void DoUpdate(int);

private:
	int m_iSpeed;
	int m_iShotDelay;
};

