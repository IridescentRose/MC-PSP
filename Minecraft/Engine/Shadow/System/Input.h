#pragma once

#include <malloc.h>
#include <pspkernel.h>
#include <pspctrl.h>
#include <psputility.h>
#include <string.h>

namespace Shadow::System::Input {

	//input
	void InputUpdate();
	bool KeyPressed(PspCtrlButtons button);
	bool KeyHold(PspCtrlButtons button);
	float GetAnalogX();
	float GetAnalogY();
}