#include "Input.hpp"
#include "Timer.hpp"

namespace Shadow::Utils{
void Input::Update()
{
	old = current;
	sceCtrlReadBufferPositive(&current, 1);
}

bool Input::isKeyDown(PspCtrlButtons button)
{
	if (current.Buttons != old.Buttons)
	{
		if (current.Buttons & button)
		{
			return true;
		}
	}
	return false;
}

bool Input::isActionDown(InputAction action)
{
	switch (action) {
	case PSP_ANALOG_UP:

		if (getY() > 0.4f) {
			return true;
		}

		break;

	case PSP_ANALOG_DOWN:

		if (getY() < -0.4f) {
			return true;
		}

		break;

	case PSP_ANALOG_LEFT:

		if (getX() < -0.4f) {
			return true;
		}

		break;

	case PSP_ANALOG_RIGHT:

		if (getX() > 0.4f) {
			return true;
		}

		break;

	case PSP_UP:
		return isKeyDown(PSP_CTRL_UP);
		break;

	case PSP_DOWN:
		return isKeyDown(PSP_CTRL_DOWN);
		break;

	case PSP_LEFT:
		return isKeyDown(PSP_CTRL_LEFT);
		break;

	case PSP_RIGHT:
		return isKeyDown(PSP_CTRL_RIGHT);
		break;

	case PSP_START:
		return isKeyDown(PSP_CTRL_START);
		break;

	case PSP_SELECT:
		return isKeyDown(PSP_CTRL_SELECT);
		break;

	case PSP_RIGHT_TRIGGER:
		return isKeyDown(PSP_CTRL_RTRIGGER);
		break;

	case PSP_LEFT_TRIGGER:
		return isKeyDown(PSP_CTRL_LTRIGGER);
		break;

	case PSP_CROSS:
		return isKeyDown(PSP_CTRL_CROSS);
		break;

	case PSP_CIRCLE:
		return isKeyDown(PSP_CTRL_CIRCLE);
		break;

	case PSP_SQUARE:
		return isKeyDown(PSP_CTRL_SQUARE);
		break;
	case PSP_TRIANGLE:
		return isKeyDown(PSP_CTRL_TRIANGLE);
		break;
	}

	return false;
}

bool Input::isKeyHeld(PspCtrlButtons button)
{
	if (current.Buttons & button)
	{
		return true;
	}
	return false;
}

bool Input::isActionHeld(InputAction action)
{
	switch (action) {
	case PSP_ANALOG_UP:

		if (getY() > 0.4f) {
			return true;
		}

		break;

	case PSP_ANALOG_DOWN:

		if (getY() < -0.4f) {
			return true;
		}

		break;

	case PSP_ANALOG_LEFT:

		if (getX() < -0.4f) {
			return true;
		}

		break;

	case PSP_ANALOG_RIGHT:

		if (getX() > 0.4f) {
			return true;
		}

		break;

	case PSP_UP:
		return isKeyHeld(PSP_CTRL_UP);
		break;

	case PSP_DOWN:
		return isKeyHeld(PSP_CTRL_DOWN);
		break;

	case PSP_LEFT:
		return isKeyHeld(PSP_CTRL_LEFT);
		break;

	case PSP_RIGHT:
		return isKeyHeld(PSP_CTRL_RIGHT);
		break;

	case PSP_START:
		return isKeyHeld(PSP_CTRL_START);
		break;

	case PSP_SELECT:
		return isKeyHeld(PSP_CTRL_SELECT);
		break;

	case PSP_RIGHT_TRIGGER:
		return isKeyHeld(PSP_CTRL_RTRIGGER);
		break;

	case PSP_LEFT_TRIGGER:
		return isKeyHeld(PSP_CTRL_LTRIGGER);
		break;

	case PSP_CROSS:
		return isKeyHeld(PSP_CTRL_CROSS);
		break;

	case PSP_CIRCLE:
		return isKeyHeld(PSP_CTRL_CIRCLE);
		break;

	case PSP_SQUARE:
		return isKeyHeld(PSP_CTRL_SQUARE);
		break;
	case PSP_TRIANGLE:
		return isKeyHeld(PSP_CTRL_TRIANGLE);
		break;
	}

	return false;
}

InputAction Input::nextAction()
{

	Timer t;
	t = Timer();

	float delay = 0.1f;

	while (delay > 0) {
		delay -= t.deltaTime();
		Update();
	}

	delay = 2.0f;
	while (delay > 0) {
		delay -= t.deltaTime();
		Update();

		//check each button
		if (isKeyDown(PSP_CTRL_UP)) {
			return PSP_UP;
		}

		if (isKeyDown(PSP_CTRL_DOWN)) {
			return PSP_DOWN;
		}
		if (isKeyDown(PSP_CTRL_LEFT)) {
			return PSP_LEFT;
		}
		if (isKeyDown(PSP_CTRL_RIGHT)) {
			return PSP_RIGHT;
		}

		if (isKeyDown(PSP_CTRL_TRIANGLE)) {
			return PSP_TRIANGLE;
		}
		if (isKeyDown(PSP_CTRL_CROSS)) {
			return PSP_CROSS;
		}
		if (isKeyDown(PSP_CTRL_SQUARE)) {
			return PSP_SQUARE;
		}
		if (isKeyDown(PSP_CTRL_CIRCLE)) {
			return PSP_CIRCLE;
		}

		if (isKeyDown(PSP_CTRL_LTRIGGER)) {
			return PSP_LEFT_TRIGGER;
		}
		if (isKeyDown(PSP_CTRL_RTRIGGER)) {
			return PSP_RIGHT_TRIGGER;
		}
		if (isKeyDown(PSP_CTRL_SELECT)) {
			return PSP_SELECT;
		}
		if (isKeyDown(PSP_CTRL_START)) {
			return PSP_START;
		}

		if (getX() >= 0.8f) {
			return PSP_ANALOG_RIGHT;
		}

		if (getX() <= -0.8f) {
			return PSP_ANALOG_LEFT;
		}
		if (getY() <= -0.8f) {
			return PSP_ANALOG_DOWN;
		}
		if (getY() >= 0.8f) {
			return PSP_ANALOG_UP;
		}
	}

	return InputAction(0);
}

float Input::getX()
{
	return (((float)current.Lx - 122.5f) / 122.5f); //Range of +/- 1.0f
}

float Input::getY()
{
	return (((float)current.Ly - 122.5f) / 122.5f); //Range of +/- 1.0f
}

Input input = Input();

std::string toString(InputAction inputs) {
	switch (inputs) {
	case PSP_ANALOG_DOWN:
		return "Analog Down";

		break;
	case PSP_ANALOG_UP:
		return "Analog Up";

		break;
	case PSP_ANALOG_LEFT:
		return "Analog Left";

		break;
	case PSP_ANALOG_RIGHT:
		return "Analog Right";

		break;



	case PSP_DOWN:
		return "Down";

		break;
	case PSP_UP:
		return "Up";

		break;
	case PSP_LEFT:
		return "Left";

		break;
	case PSP_RIGHT:
		return "Right";

		break;

		
	case PSP_CROSS:
		return "Cross";

		break;
	case PSP_CIRCLE:
		return "Circle";

		break;
	case PSP_TRIANGLE:
		return "Triangle";

		break;
	case PSP_SQUARE:
		return "Square";

		break;


	case PSP_RIGHT_TRIGGER:
		return "RTrigger";

		break;
	case PSP_LEFT_TRIGGER:
		return "LTrigger";

		break;
	case PSP_SELECT:
		return "Select";

		break;
	case PSP_START:
		return "Start";

		break;

	}

	return "";
}
}