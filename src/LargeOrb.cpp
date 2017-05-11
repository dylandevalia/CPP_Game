#include "LargeOrb.h"
#include "SmallOrb.h"
#include "Utility.h"

LargeOrb::LargeOrb(GameEngine* pEngine, GameTileManager* pTile, bool tile, int xpos, int ypos)
	: PlasmaOrb(
	    pEngine, pTile,
		tile,
		xpos, ypos,
		Utility::map(rand() % 2, 0, 1, -1, 1),
		Utility::map(rand() % 2, 0, 1, -1, 1),
		1, 200, 5
	)
{
	//m_sprite.LoadImage("spritesheet.png");
}

LargeOrb::~LargeOrb() {
}


/* Used to draw the object */
void LargeOrb::Draw() {
	if (m_iDmg-- > 0) {
		m_sSprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			200, 100,                              // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			200, 200,                                      // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	} else {
		m_sSprite.FlexibleRenderImageWithMask(
			GetEngine()->GetForeground(),                        // Surface
			0, 100,                                // Start coords in image
			m_iCurrentScreenX, m_iCurrentScreenY, // Start coords on screen
			200, 200,                                      // Width, height
			0,                        // Number of 90* clockwise roatations
			0, 0,                                     // Transparency pixel
			100,                                   // Brightness percentage
			-1, -1, -1, -1                     // Alternating pixel colours
		);
	}

	StoreLastScreenPositionForUndraw();
}

/* Called on entity death */
void LargeOrb::onDeath() {
	GameEngine* pEngine = GetEngine();
	// Spawn 4 small orbs
	pEngine->DrawableObjectsChanged();
	int x = GetXCentre(), y = GetYCentre();
	pEngine->StoreObjectInArrayAtEnd(new SmallOrb(pEngine, m_pTile, false, x-25, y-25, -1, -1));
	pEngine->StoreObjectInArrayAtEnd(new SmallOrb(pEngine, m_pTile, false, x + 25, y - 25, 1, -1));
	pEngine->StoreObjectInArrayAtEnd(new SmallOrb(pEngine, m_pTile, false, x - 25, y + 25, -1, 1));
	pEngine->StoreObjectInArrayAtEnd(new SmallOrb(pEngine, m_pTile, false, x + 25, y + 25, 1, 1));
	pEngine->SetObjectVisibility(true);
	RedrawObjects();

	deleteSelf();
} 