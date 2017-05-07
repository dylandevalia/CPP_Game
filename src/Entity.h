#pragma once
#include "header.h"
#include "templates.h"

#include "DisplayableObject.h"
class Entity :
	public DisplayableObject {
public:
	Entity(BaseEngine*, int, int, int, int, int);
	~Entity();

	/* Takes damage from health value */
	void dealDamage(double damage) { m_iCurHealth - damage; }
	/* Returns the entity's current health */
	double getHealth() { return m_iCurHealth; }
	/* Returns the entity's maximum health */
	double getMaxHealth() { return m_iMaxHealth; }

protected:
	/* Entity health */
	int m_iMaxHealth, m_iCurHealth;
};

