#pragma once

#include <malloc.h>
#include <pspkernel.h>
#include <pspctrl.h>
#include <psputility.h>
#include <json/json.h>
#include <string.h>

#define PSP_CTRL_ANALOG_X 0x2
#define PSP_CTRL_ANALOG_Y 0x4

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
}