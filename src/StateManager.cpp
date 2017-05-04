#include "StateManager.h"
#include "MenuState.h"
#include "PlayState.h"
#include "PauseState.h"

#define NUM_OF_STATES 3

/**
Manages all the states
*/
StateManager::StateManager(GameEngine* pEngine, GameState state)
	: m_pEngine(pEngine) 
{
	m_aStates = new State*[NUM_OF_STATES];
	for (int i = 0; i < NUM_OF_STATES; m_aStates[i++] = nullptr);

	initState(state);
	setState(state);
}

StateManager::~StateManager() {}

/**
Initialises the state and runs its initialise function

@param state The state to initialise
*/
void StateManager::initState(GameState state) {
	switch (state) {
		case GameState::MENU:
			m_aStates[0] = new MenuState(m_pEngine, this);
			m_aStates[0]->init();
			break;
		case GameState::PLAY:
			m_aStates[1] = new PlayState(m_pEngine, this);
			m_aStates[1]->init();
			break;
		/*
		case GameState::StageOne:
		.   m_aStates[1] = new StageOneState(..);  // Overridding index 1
		case GameState::StateTwo:
		.   m_aStates[1] = new StateTwoState(..);
		*/
		case GameState::PAUSE:
			m_aStates[2] = new PauseState(m_pEngine, this);
			m_aStates[2]->init();
			break;
	}
}

/**
Sets the current state and runs its setup function

@param state The state to set to current state
*/
void StateManager::setState(GameState state) {
	switch (state) {
		case MENU:
			m_pCurrrentState = m_aStates[0];
			break;
		case PLAY:
			m_pCurrrentState = m_aStates[1];
			break;
		case PAUSE:
			m_pCurrrentState = m_aStates[2];
			break;
	}
	m_pCurrrentState->setup();
}

/** 
Unloads the state and deletes all its content

@param state Unloads this state
*/
void StateManager::unloadState(GameState state) {
	switch (state) {
		case MENU:
			delete m_aStates[0];
			m_aStates[0] = nullptr;
			break;
		case PLAY:
			delete m_aStates[1];
			m_aStates[1] = nullptr;
			break;
		case PAUSE:
			delete m_aStates[2];
			m_aStates[2] = nullptr;
			break;
	}
}

/**
Checks if a state is loaded

@param state The state to check if it's loaded

@return Boolean if state is loaded
*/
bool StateManager::isLoaded(GameState state) {
	switch (state) {
		case MENU:
			return (m_aStates[0] != nullptr);
			break;
		case PLAY:
			return (m_aStates[1] != nullptr);
			break;
		case PAUSE:
			return (m_aStates[2] != nullptr);
			break;
		default:
			return false;
			break;
	}
}