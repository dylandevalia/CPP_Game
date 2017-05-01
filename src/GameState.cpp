#include "GameState.h"

/**
State interface
*/

void GameState::setup() {}
void GameState::update() {}
void GameState::draw() {}

/* Events */
void GameState::keyDown(int) {}
void GameState::keyUp(int) {}
void GameState::mouseMoved(int, int) {}
void GameState::mouseDown(int, int, int) {}
void GameState::mouseUp(int, int, int) {}