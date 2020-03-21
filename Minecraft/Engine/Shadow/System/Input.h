#pragma once

#include <malloc.h>
#include <pspkernel.h>
#include <pspctrl.h>
#include <psputility.h>
#include <json/json.h>
#include <Utilities/Timer.h>
#include <string.h>

#define PSP_CTRL_ANALOG_UP 0x2
#define PSP_CTRL_ANALOG_RIGHT 0x4

#define PSP_CTRL_ANALOG_DOWN 0x3
#define PSP_CTRL_ANALOG_LEFT 0x5

namespace Shadow::System::Input {

	//input
	void InputUpdate();
	bool KeyPressed(PspCtrlButtons button);
	bool KeyHold(PspCtrlButtons button);
	float GetAnalogX();
	float GetAnalogY();

	typedef void (*ActionHandler)();

	void checkActions();
	void registerActionHandler(ActionHandler act, std::string str);
	void loadConfiguration(std::string name);
	void writeConfiguration(std::string name);

	void makeDefaultConfig();

	PspCtrlButtons findButtonPair(std::string str);

	extern std::map<int, std::string> actions;
	extern std::map<std::string, ActionHandler> handlers;

	std::string toString(int but);
	PspCtrlButtons nextAction();
}