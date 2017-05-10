#include "SmallOrb.h"
#include "Spider.h"

SmallOrb::SmallOrb(GameEngine* pEngine, GameTileManager* pTile, bool tile, int xpos, int ypos, int xdir, int ydir)
	: PlasmaOrb(pEngine, pTile, tile, xpos, ypos, xdir, ydir, 2, 50, 3)
{
}

SmallOrb::SmallOrb(GameEngine* pEngine, GameTileManager* pTile, bool tile, int xpos, int ypos)
	: PlasmaOrb(pEngine, pTile, tile, xpos, ypos, rand() % 2 == 0 ? -1 : 1, rand() % 2 == 0 ? -1 : 1, 2, 50, 3)
{

}

SmallOrb::~SmallOrb() {
}

void SmallOrb::Draw() {
	if (m_iDmg-- > 0) {
		m_sSprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			50, 300,                               // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			50, 50,                                        // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	} else {
		m_sSprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			0, 300,                                // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			50, 50,                                        // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	}

	StoreLastScreenPositionForUndraw();
}

void SmallOrb::onDeath() {
	GameEngine* pEngine = GetEngine();
	pEngine->DrawableObjectsChanged();
	int x = GetXCentre(), y = GetYCentre();
	//pEngine->StoreObjectInArrayAtEnd(new Spider(pEngine, x - 10, y - 10));
	//pEngine->StoreObjectInArrayAtEnd(new Spider(pEngine, x + 10, y + 10));
	pEngine->SetObjectVisibility(true);
	RedrawObjects();
}
