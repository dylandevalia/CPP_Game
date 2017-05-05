#include "header.h"
#include "templates.h"

#include "Game.h"
#include "Demo4Main.h"

#include <ctime>

#define SCREEN_WIDTH 750
#define SCREEN_HEIGHT 450

int main(int argc, char *argv[]) {
	int iResult;

	// Send random number generator with current time
	::srand(time(0));

	Game g;
	//Demo4Main oMain;

	char buf[1024];

	iResult = g.Initialise(NULL, SCREEN_WIDTH, SCREEN_HEIGHT, "VT323-Regular.ttf", 24);

	g.m_GSM.initState(GameState::MENU);
	g.m_GSM.setState(GameState::MENU);

	iResult = g.MainLoop();
	g.Deinitialise();

	return iResult;
}
