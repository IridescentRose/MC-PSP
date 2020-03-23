#pragma once

#include "StateManager.h"

class GameState{
public:
	virtual void Init() = 0;
	virtual void CleanUp() = 0;
	virtual void Enter() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;
	virtual void Update(StateManager* sManager) = 0;
	virtual void Draw(StateManager* sManager) = 0;
	void ChangeState(StateManager* sManager, GameState* state)
	{
		sManager->ChangeState(state);
	}
protected:
	GameState() { }
};