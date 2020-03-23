#pragma once
#include <vector>

class GameState;

class StateManager{
public:
	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();
	void Update();
	void Draw();

    bool running;
private:
	std::vector<GameState*> states;
};