#include "LargeOrb.h"
#include "SmallOrb.h"
#include "Utility.h"

LargeOrb::LargeOrb(GameEngine* pEngine, int xpos, int ypos)
	: PlasmaOrb(
	    pEngine, true,
		xpos, ypos,
		Utility::map(rand() % 2, 0, 1, -1, 1),
		Utility::map(rand() % 2, 0, 1, -1, 1),
		1, 200, 3
	)
{
}


LargeOrb::~LargeOrb() {
}

void LargeOrb::onDeath() {
	GameEngine* pEngine = GetEngine();
	pEngine->DrawableObjectsChanged();
	int x = GetXCentre(), y = GetYCentre();
	pEngine->StoreObjectInArrayAtEnd(new SmallOrb(pEngine, x-25, y-25, -1, -1));
	pEngine->StoreObjectInArrayAtEnd(new SmallOrb(pEngine, x+25, y-25, 1, -1));
	pEngine->StoreObjectInArrayAtEnd(new SmallOrb(pEngine, x-25, y+25, -1, 1));
	pEngine->StoreObjectInArrayAtEnd(new SmallOrb(pEngine, x+25, y+25, 1, 1));
	pEngine->SetObjectVisibility(true);
	RedrawObjects();
} 