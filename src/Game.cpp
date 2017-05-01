#include "Game.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

/**
Object which extends base engine
handles draw and main loop
*/
Game::Game()
	: GameEngine(20),            // Maximum number of moving objects
	m_GSM(this, GameState::MENU) // Start in menu state
{
	Initialise(NULL, SCREEN_WIDTH, SCREEN_HEIGHT, "VT323-Regular.ttf", 24);

	MainLoop();

	Deinitialise();
}

Game::~Game() {

}

int Game::MainLoop(void) {
	{
		SDL_Event event;
		int iKeyCode;

		// Main loop: loop until told not to
		while (m_iExitWithCode == -1) {
			// Render stuff
			m_iTick = SDL_GetTicks();

			// Poll for events, and handle the ones we care about.
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
					case SDL_KEYDOWN:
						//printf("Key down: %d, '%c'\n", SymbolToKeycode(event.key.keysym.sym), event.key.keysym.sym);
						m_pKeyStatus[SymbolToKeycode(event.key.keysym.sym)] = true;
						KeyDown(event.key.keysym.sym);
						break;

					case SDL_KEYUP:
						//printf("Key up: %d, '%c'\n", SymbolToKeycode(event.key.keysym.sym), event.key.keysym.sym);
						m_pKeyStatus[SymbolToKeycode(event.key.keysym.sym)] = false;
						KeyUp(event.key.keysym.sym);
						break;

					case SDL_MOUSEMOTION:
						m_iCurrentMouseX = event.motion.x;
						m_iCurrentMouseY = event.motion.y;
						MouseMoved(event.motion.x, event.motion.y);
						break;

					case SDL_MOUSEBUTTONDOWN:
						m_iMouseXClickedDown = event.button.x;
						m_iMouseYClickedDown = event.button.y;
						MouseDown(event.button.button, event.button.x, event.button.y);
						break;

					case SDL_MOUSEBUTTONUP:
						m_iMouseXClickedUp = event.button.x;
						m_iMouseYClickedUp = event.button.y;
						MouseUp(event.button.button, event.button.x, event.button.y);
						break;

					case SDL_QUIT:
						return 0;
				}
			}

			m_GSM.update();

			// Do any updates for movements
			GameAction();

			m_GSM.draw();

			// Render the screen
			GameRender();
		}
		return 0;
	}
}