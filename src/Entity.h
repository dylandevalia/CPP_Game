#pragma once
#include "header.h"
#include "templates.h"

#include "JPGImage.h"
#include "DisplayableObject.h"

class Entity :
	public DisplayableObject {
public:
	Entity(GameEngine*, bool, int, int, int, int, int);
	~Entity();

	/* Takes damage from health value */
	void dealDamage(double damage) { m_iCurHealth -= damage; m_iDmg = 5; }
	/* Returns the entity's current health */
	double getHealth() { return m_iCurHealth; }
	/* Returns the entity's maximum health */
	double getMaxHealth() { return m_iMaxHealth; }

	/* Function to run on entity death */
	void onDeath() {}

	/* Constrains the entity within the bounds of the screen */
	void constrainInBounds();
	/* Checks if the entity is outside of the screen */
	bool checkBounds();
	/* Returns distance squared between entities */
	int getDistanceBetween(Entity*);
	/* Checks if the entity is colliding with the given entity */
	bool checkIntersection(Entity*);

	/* Deletes itself from the object array */
	void deleteSelf();

protected:
	/* Entity health */
	int m_iMaxHealth, m_iCurHealth, m_iDmg;
	//bool m_bCurDamaged;

	ImageData m_sSprite;
};

