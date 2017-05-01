#include "GameStateMain.h"

#include <iostream>

using namespace std;

GameStateMain::GameStateMain(BaseEngine* pGame)
	: pGame(pGame)
{
	
}


GameStateMain::~GameStateMain()
{

}

void GameStateMain::setup(){
	pGame->FillBackground(0xAABBAA);
}

void GameStateMain::update(){

}

void GameStateMain::draw(){	
}

