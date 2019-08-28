#include "ActionConverter.hpp"

#include <Shadow/Utils/Input.hpp>

namespace Minecraft::Common{
    using namespace Shadow::Utils;
bool ActionManager::actionPressedDown(Actions action){
	switch(action){
		case GAME_JUMP:
			
			return input.isActionDown((InputAction)g_Control.jump);
			
			break;
			
			
		case GAME_DESTROY:
			
			return input.isActionDown((InputAction)g_Control.destroy);
			
			break;
			
			
		case GAME_PLACE:
			
			return input.isActionDown((InputAction)g_Control.place);
			
			break;
			
			
		case GAME_WALK_UP:
			
			return input.isActionDown((InputAction)g_Control.walkUp);
			
			break;
			
			
		case GAME_WALK_DOWN:
			
			return input.isActionDown((InputAction)g_Control.walkDown);
			
			break;
			
			
		case GAME_WALK_LEFT:
			
			return input.isActionDown((InputAction)g_Control.walkLeft);
			
			break;
			
			
		case GAME_WALK_RIGHT:
			
			return input.isActionDown((InputAction)g_Control.walkRight);
			
			break;
			
			
		case GAME_LOOK_UP:
			
			return input.isActionDown((InputAction)g_Control.lookUp);
			
			break;
			
			
		case GAME_LOOK_DOWN:
			
			return input.isActionDown((InputAction)g_Control.lookDown);
			
			break;
			
		case GAME_LOOK_LEFT:
			
			return input.isActionDown((InputAction)g_Control.lookLeft);
			
			break;
			
		case GAME_LOOK_RIGHT:
			
			return input.isActionDown((InputAction)g_Control.lookRight);
			
			break;
			
		case GAME_HOT_LEFT:
			return input.isActionDown((InputAction)g_Control.hotLeft);
				
			break;
			
			
		case GAME_HOT_RIGHT:
			return input.isActionDown((InputAction)g_Control.hotRight);
				
			break;
			
				
		case GAME_PAUSE:
			return input.isActionDown((InputAction)g_Control.pauseMenu);
				
			break;
			
					
		case GAME_SPRINT:
			return input.isActionDown((InputAction)g_Control.toggleSprint);
				
			break;

		case GAME_CROUCH:
			return input.isActionDown((InputAction)g_Control.toggleCrouch);
				
			break;
			
			
	}
}

bool ActionManager::actionHeldDown(Actions action){
	switch(action){
		case GAME_JUMP:
			
			return input.isActionHeld((InputAction)g_Control.jump);
			
			break;
			
			
		case GAME_DESTROY:
			
			return input.isActionHeld((InputAction)g_Control.destroy);
			
			break;
			
			
		case GAME_PLACE:
			
			return input.isActionHeld((InputAction)g_Control.place);
			
			break;
			
			
		case GAME_WALK_UP:
			
			return input.isActionHeld((InputAction)g_Control.walkUp);
			
			break;
			
			
		case GAME_WALK_DOWN:
			
			return input.isActionHeld((InputAction)g_Control.walkDown);
			
			break;
			
			
		case GAME_WALK_LEFT:
			
			return input.isActionHeld((InputAction)g_Control.walkLeft);
			
			break;
			
			
		case GAME_WALK_RIGHT:
			
			return input.isActionHeld((InputAction)g_Control.walkRight);
			
			break;
			
			
		case GAME_LOOK_UP:
			
			return input.isActionHeld((InputAction)g_Control.lookUp);
			
			break;
			
			
		case GAME_LOOK_DOWN:
			
			return input.isActionHeld((InputAction)g_Control.lookDown);
			
			break;
			
		case GAME_LOOK_LEFT:
			
			return input.isActionHeld((InputAction)g_Control.lookLeft);
			
			break;
			
		case GAME_LOOK_RIGHT:
			
			return input.isActionHeld((InputAction)g_Control.lookRight);
			
			break;
			
		case GAME_HOT_LEFT:
			return input.isActionHeld((InputAction)g_Control.hotLeft);
				
			break;
			
			
		case GAME_HOT_RIGHT:
			return input.isActionHeld((InputAction)g_Control.hotRight);
				
			break;
			
				
		case GAME_PAUSE:
			return input.isActionHeld((InputAction)g_Control.pauseMenu);
				
			break;
			
					
		case GAME_SPRINT:
			return input.isActionHeld((InputAction)g_Control.toggleSprint);
				
			break;
			
        case GAME_CROUCH:
            return input.isActionHeld((InputAction)g_Control.toggleCrouch);
            break;
			
	}
}

ActionManager action = ActionManager();
}