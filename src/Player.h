#pragma once
#include "Entity.h"
class Player :
	public Entity {
public:
	Player(BaseEngine*, int, int);
	~Player();

	void Draw();
	void DoUpdate(int);

private:
	int m_iSpeed;
};

