#include "LargeOrb.h"
#include "SmallOrb.h"

LargeOrb::LargeOrb(GameEngine* pEngine, int xpos, int ypos)
	: PlasmaOrb(pEngine, true, xpos, ypos, 1, 150, 3)
{
}


LargeOrb::~LargeOrb() {
}

void LargeOrb::onDeath() {
	printf("a\n");
	GameEngine* pEngine = GetEngine();
	pEngine->DrawableObjectsChanged();
	pEngine->StoreObjectInArrayAtEnd(new SmallOrb(pEngine, m_iCurrentScreenX-25, m_iCurrentScreenY-25));
	pEngine->StoreObjectInArrayAtEnd(new SmallOrb(pEngine, m_iCurrentScreenX+25, m_iCurrentScreenY-25));
	pEngine->StoreObjectInArrayAtEnd(new SmallOrb(pEngine, m_iCurrentScreenX-25, m_iCurrentScreenY+25));
	pEngine->StoreObjectInArrayAtEnd(new SmallOrb(pEngine, m_iCurrentScreenX+25, m_iCurrentScreenY+25));
	pEngine->SetObjectVisibility(true);
	RedrawObjects();
}