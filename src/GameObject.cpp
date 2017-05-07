#include "GameObject.h"


GameObject::GameObject(GameEngine* pEngine)
	: DisplayableObject(pEngine),
	m_pGame(pEngine)
{

}

GameObject::~GameObject()
{
}
