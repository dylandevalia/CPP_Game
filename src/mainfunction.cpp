#include "header.h"
#include "templates.h"

#include "Game.h"
#include "Demo4Main.h"

#include <ctime>

#define BASE_SCREEN_WIDTH 800
#define BASE_SCREEN_HEIGHT 600

int main(int argc, char *argv[]) {
	int iResult;

	// Send random number generator with current time
	::srand(time(0));

	Game g;
	//Demo4Main oMain;

	char buf[1024];
	sprintf(buf, "My Demonstration Program : Size %d x %d", BASE_SCREEN_WIDTH, BASE_SCREEN_HEIGHT);
	//iResult = oMain.Initialise(buf, BASE_SCREEN_WIDTH, BASE_SCREEN_HEIGHT, "Cornerstone Regular.ttf", 24);
	//iResult = oMain.MainLoop();
	//oMain.Deinitialise();

	return iResult;
}
