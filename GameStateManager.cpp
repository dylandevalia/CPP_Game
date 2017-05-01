#include "GameStateManager.h"

GameStateManager::GameStateManager(BaseEngine* game,int newState)
	: pGame(game)
{
	state = new GameStateMain(pGame);
	setState(newState);
}

GameStateManager::~GameStateManager()
{

}

void GameStateManager::setState(int newState){

	delete state;

	if (newState == MAIN){
		state = new GameStateMain(pGame);
	}
	else if (newState == START){

	}
	else if (newState == PAUSE){

	}
	else if (newState == WIN){

	}
	else if (newState == LOSE){

	}
	else{
		state = new GameStateMain(pGame);
	}
}


