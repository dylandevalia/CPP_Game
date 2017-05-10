#pragma once
#include "Entity.h"
class Player :
	public Entity {
public:
	Player(GameEngine*, GameTileManager*, bool, int, int);
	~Player();

	void Draw();
	void DoUpdate(int);

	void onDeath();

	void move(GameEngine*);
	void shoot(GameEngine*);
	void hit(GameEngine*);

private:
	int m_iSpeed;
	int m_iShotDelay;
	int m_iIFrame;
};

