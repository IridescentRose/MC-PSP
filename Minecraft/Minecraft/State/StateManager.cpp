#include "GameState.h"
#include "StateManager.h"

void StateManager::ChangeState(GameState* state){
	// cleanup the state chain
	while ( !states.empty() ) {
		states.back()->CleanUp();
		states.pop_back();
	}
	
    // store and init the new state
	states.push_back(state);
	states.back()->Enter();
}

void StateManager::PushState(GameState* state){
	// pause current state
	if ( !states.empty() ) {
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Enter();
}

void StateManager::PopState(){
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->CleanUp();
		delete states.back();
		states.pop_back();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}

void StateManager::Update(){
	states.back()->Update(this);
}

void StateManager::Draw(){
	states.back()->Draw(this);
}