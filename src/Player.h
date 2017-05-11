#pragma once
#include "Entity.h"
#include "StateManager.h"

class Player :
	public Entity {
public:
	Player(GameEngine*, GameTileManager*, StateManager*, bool, int, int);
	Player(GameEngine*, GameTileManager*, StateManager*);
	~Player();

	/* Sets the players position*/
	void setPos(bool, int, int);

	/* Used to draw object */
	void Draw();
	/* Called to update the object */
	void DoUpdate(int);

	/* Called on entity death */
	void onDeath();

	/* Handles movement of the player with keypresses */
	void move(GameEngine*);
	/* Handles shooting with keypresses */
	void shoot(GameEngine*);
	/* Calculates if the player has been hit */
	void hit(GameEngine*);

private:
	int m_iSpeed;
	int m_iShotDelay;
	int m_iIFrame;
	bool m_bHoming;

	char strLives[50];

	StateManager* m_pState;
};

