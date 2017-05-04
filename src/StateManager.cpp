#include "StateManager.h"
#include "MenuState.h"
#include "PlayState.h"
#include "PauseState.h"

/**
Manages all the states
*/
StateManager::StateManager(GameEngine* pEngine, GameState state)
	: m_pEngine(pEngine) 
{
	m_aStates = new State*[3];
	for (int i = 0; i < 3; m_aStates[i++] = nullptr);

	initState(state);
	setState(state);
}

StateManager::~StateManager() {}

/**
Initialises the state and runs it's setup

@param state The state to initialise
*/
void StateManager::initState(GameState state) {
	switch (state) {
		case GameState::MENU:
			m_aStates[0] = new MenuState(m_pEngine, this);
			m_aStates[0]->setup();
			break;
		case GameState::PLAY:
			m_aStates[1] = new PlayState(m_pEngine, this);
			m_aStates[1]->setup();
			break;
		/*
		case GameState::StageOne:
		.   m_aStates[1] = new StageOneState(..);  // Overridding index 1
		case GameState::StateTwo:
		.   m_aStates[1] = new StateTwoState(..);
		*/
		case GameState::PAUSE:
			m_aStates[2] = new PauseState(m_pEngine, this);
			m_aStates[2]->setup();
			break;
	}
}

/**
Sets the current state

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