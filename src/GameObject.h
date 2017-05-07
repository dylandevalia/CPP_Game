#pragma once
#include "header.h"
#include "templates.h"

#include "DisplayableObject.h"
#include "GameEngine.h"

class GameObject :
	public DisplayableObject
{
public:
	GameObject(GameEngine*);
	~GameObject();

	inline GameEngine* GetEngine() { return m_pGame; }

protected:
	GameEngine* m_pGame;
};

