#pragma once

#include <pspctrl.h>
#include <string>

namespace Shadow::Utils{

    enum InputAction {
	    PSP_CROSS = 0,
	    PSP_CIRCLE = 1,
	    PSP_SQUARE = 2,
	    PSP_TRIANGLE = 3,
	    PSP_ANALOG_UP = 4,
	    PSP_ANALOG_DOWN = 5,
	    PSP_ANALOG_LEFT = 6,
	    PSP_ANALOG_RIGHT = 7,
	    PSP_START = 8,
	    PSP_SELECT = 9,
	    PSP_RIGHT_TRIGGER = 10,
	    PSP_LEFT_TRIGGER = 11,
    	PSP_UP = 12,
	    PSP_DOWN = 13,
	    PSP_LEFT = 14, 
	    PSP_RIGHT = 15
    };

    std::string toString(InputAction input);

    class Input {
    public:
	    void Update();
	
	    bool isKeyDown(PspCtrlButtons button);
	    bool isActionDown(InputAction action);
	    bool isKeyHeld(PspCtrlButtons button);
	    bool isActionHeld(InputAction action);

	    InputAction nextAction();
	
	    float getX();
	    float getY();

    private:
	    SceCtrlData old, current;
    };

    extern Input input;

}