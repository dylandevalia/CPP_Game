#include "Game.h"

Game::Game()
	: BaseEngine(20), GSM(this, 0)
{
	Initialise(NULL, 600, 600, "Cornerstone Regular.ttf", 24);

	MainLoop();
	
	Deinitialise();

}

Game::~Game()
{

}

int Game::MainLoop(void){
	{

		GSM.setup();

		/// Main loop: loop until told not to
		while (m_iExitWithCode == -1)
		{
			PollKeyEvents();

			GSM.update();

			// Do any updates for movements
			GameAction();

			GSM.draw();

			// Render the screen
			GameRender();
		}

		return 0;
	}
}