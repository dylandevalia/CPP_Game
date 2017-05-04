#pragma once
class State {
public:
	virtual void init();
	virtual void setup();
	virtual void update();
	virtual void draw();

	// Events

	virtual void keyDown(int);
	virtual void keyUp(int);
	virtual void mouseMoved(int, int);
	virtual void mouseDown(int, int, int);
	virtual void mouseUp(int, int, int);

	// Overides

	virtual int initialiseObjects();
	virtual void setupBackgroundBuffer();
	virtual void drawStrings();
};

