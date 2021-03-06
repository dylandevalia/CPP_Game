#include "State.h"


/**
State interface
*/

void State::init() {}
void State::setup() {}
void State::update() {}
void State::draw() {}

// Events

void State::keyDown(int) {}
void State::keyUp(int) {}
void State::mouseMoved(int, int) {}
void State::mouseDown(int, int, int) {}
void State::mouseUp(int, int, int) {}

// Overides

int State::initialiseObjects() { return 0; }
void State::setupBackgroundBuffer() {}
void State::drawStrings() {}

