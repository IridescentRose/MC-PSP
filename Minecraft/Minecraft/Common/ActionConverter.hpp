#pragma once
#include "Controls.hpp"

namespace Minecraft::Common{
    using namespace Shadow::Utils;
enum Actions{
	GAME_JUMP,
	GAME_DESTROY,
	GAME_PLACE,
	
	GAME_WALK_UP,
	GAME_WALK_DOWN,
	GAME_WALK_LEFT,
	GAME_WALK_RIGHT,
	
	GAME_LOOK_UP,
	GAME_LOOK_DOWN,
	GAME_LOOK_LEFT,
	GAME_LOOK_RIGHT,
	
	GAME_HOT_LEFT,
	GAME_HOT_RIGHT,
	GAME_SPRINT,
    GAME_CROUCH,

	GAME_PAUSE,
};
class ActionManager{
	public:
		
	bool actionPressedDown(Actions action);
	bool actionHeldDown(Actions action);	
};

extern ActionManager action;
}