#include "Input.h"

namespace Shadow::System::Input {

	SceCtrlData oldPadData;
	SceCtrlData newPadData;

	void InputUpdate()
	{
		//new to old
		oldPadData = newPadData;
		//get input data
		sceCtrlReadBufferPositive(&newPadData, 1);
	}

	bool KeyPressed(PspCtrlButtons button)
	{
		if (newPadData.Buttons != oldPadData.Buttons)
		{
			if (newPadData.Buttons & button)
			{
				return true;
			}
		}
		return false;
	}

	bool KeyHold(PspCtrlButtons button)
	{
		if (newPadData.Buttons & button)
		{
			return true;
		}

		return false;
	}

	float GetAnalogX()
	{
		return (((float)newPadData.Lx - 122.5f) / 122.5f);
	}

	float GetAnalogY()
	{
		return (((float)newPadData.Ly - 122.5f) / 122.5f);
	}
}