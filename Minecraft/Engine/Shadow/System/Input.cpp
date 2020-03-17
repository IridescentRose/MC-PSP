#include "Input.h"
#include <fstream>

namespace Shadow::System::Input {

	SceCtrlData oldPadData;
	SceCtrlData newPadData;


float getX()
{
	return (((float)newPadData.Lx - 122.5f) / 122.5f); //Range of +/- 1.0f
}

float getY()
{
	return (((float)newPadData.Ly - 122.5f) / 122.5f); //Range of +/- 1.0f
}


	void InputUpdate()
	{
		//new to old
		oldPadData = newPadData;
		//get input data
		sceCtrlReadBufferPositive(&newPadData, 1);
	}

	bool KeyPressed(PspCtrlButtons button)
	{
		if(button != PSP_CTRL_ANALOG_DOWN && button != PSP_CTRL_ANALOG_UP && button != PSP_CTRL_ANALOG_LEFT && button != PSP_CTRL_ANALOG_RIGHT){
			

		if (newPadData.Buttons != oldPadData.Buttons)
		{
			if (newPadData.Buttons & button)
			{
				return true;
			}
		}
		}else{
		
		if (getX() >= 0.5f) {
			return button == PSP_CTRL_ANALOG_RIGHT;
		}
		if (getY() >= 0.5f) {
			return button == PSP_CTRL_ANALOG_UP;
		}
		if (getX() <= -0.5f) {
			return button == PSP_CTRL_ANALOG_LEFT;
		}
		if (getY() <= -0.5f) {
			return button == PSP_CTRL_ANALOG_DOWN;
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



	std::map<int, std::string> actions;
	std::map<std::string, ActionHandler> handlers;

	void checkActions(){
		for(const auto& [but, str] : actions){
			if(KeyHold((PspCtrlButtons)but)){
				handlers[str]();
			}
		}
	}
	void registerActionHandler(ActionHandler act, std::string str){
		handlers.emplace(str, act);
	}

	void loadConfiguration(std::string name){
		actions.clear();
		std::fstream file(name);

		Json::Value root;

		file >> root;
		file.close();

		Json::Value listen = root["listeners"];

		for(int i = 0; i < listen.size(); i++){
			Json::Value temp = listen[i];
			std::string str = temp["name"].asString();
			int but = temp["button"].asInt();

			actions.emplace(but, str);
		}
	}
	void writeConfiguration(std::string name){
		std::fstream file(name, std::ios::trunc);

		Json::Value v;

		Json::Value v2(Json::arrayValue);

		for(const auto& [but, str] : actions){
			Json::Value temp;
			temp["name"] = str.c_str();
			temp["button"] = but;

			v2.append(temp);
		}

		v["listeners"] = v2;

		file << v;
		file.close();
	}


	void makeDefaultConfig(){
		actions.clear();
		handlers.clear();
	}

	PspCtrlButtons findButtonPair(std::string s){
		for(const auto& [but, str] : actions){
			if(str == s){
				return (PspCtrlButtons)but;
				break;
			}
		}

		return (PspCtrlButtons)-1;
	}

	PspCtrlButtons nextAction()
{

	Utils::Timer t;
	t = Utils::Timer();

	float delay = 0.1f;

	delay = 1.0f;
	while (delay > 0) {
		delay -= t.deltaTime();
		InputUpdate();
	}

	while (true) {
		InputUpdate();

		//check each button
		if (KeyHold(PSP_CTRL_UP)) {
			return PSP_CTRL_UP;
		}

		if (KeyHold(PSP_CTRL_DOWN)) {
			return PSP_CTRL_DOWN;
		}
		if (KeyHold(PSP_CTRL_LEFT)) {
			return PSP_CTRL_LEFT;
		}
		if (KeyHold(PSP_CTRL_RIGHT)) {
			return PSP_CTRL_RIGHT;
		}

		if (KeyHold(PSP_CTRL_TRIANGLE)) {
			return PSP_CTRL_TRIANGLE;
		}
		if (KeyHold(PSP_CTRL_CROSS)) {
			return PSP_CTRL_CROSS;
		}
		if (KeyHold(PSP_CTRL_SQUARE)) {
			return PSP_CTRL_SQUARE;
		}
		if (KeyHold(PSP_CTRL_CIRCLE)) {
			return PSP_CTRL_CIRCLE;
		}

		if (KeyHold(PSP_CTRL_LTRIGGER)) {
			return PSP_CTRL_LTRIGGER;
		}
		if (KeyHold(PSP_CTRL_RTRIGGER)) {
			return PSP_CTRL_RTRIGGER;
		}
		if (KeyHold(PSP_CTRL_SELECT)) {
			return PSP_CTRL_SELECT;
		}
		if (KeyHold(PSP_CTRL_START)) {
			return PSP_CTRL_START;
		}

		if (getX() >= 0.5f) {
			return (PspCtrlButtons)PSP_CTRL_ANALOG_RIGHT;
		}
		if (getY() >= 0.5f) {
			return (PspCtrlButtons)PSP_CTRL_ANALOG_UP;
		}
		if (getX() <= -0.5f) {
			return (PspCtrlButtons)PSP_CTRL_ANALOG_LEFT;
		}
		if (getY() <= -0.5f) {
			return (PspCtrlButtons)PSP_CTRL_ANALOG_DOWN;
		}
	}

	return (PspCtrlButtons)0;
}

	std::string toString(int inputs) {
	switch (inputs) {
	case PSP_CTRL_ANALOG_UP:
		return "Analog Up";

		break;
	
	case PSP_CTRL_ANALOG_DOWN:
		return "Analog Down";

		break;
	case PSP_CTRL_ANALOG_LEFT:
		return "Analog Left";

		break;

	case PSP_CTRL_ANALOG_RIGHT:
		return "Analog Right";

		break;



	case PSP_CTRL_DOWN:
		return "Down";

		break;
	case PSP_CTRL_UP:
		return "Up";

		break;
	case PSP_CTRL_LEFT:
		return "Left";

		break;
	case PSP_CTRL_RIGHT:
		return "Right";

		break;

		
	case PSP_CTRL_CROSS:
		return "Cross";

		break;
	case PSP_CTRL_CIRCLE:
		return "Circle";

		break;
	case PSP_CTRL_TRIANGLE:
		return "Triangle";

		break;
	case PSP_CTRL_SQUARE:
		return "Square";

		break;


	case PSP_CTRL_RTRIGGER:
		return "RTrigger";

		break;
	case PSP_CTRL_LTRIGGER:
		return "LTrigger";

		break;
	case PSP_CTRL_SELECT:
		return "Select";

		break;
	case PSP_CTRL_START:
		return "Start";

		break;

	}

	return "Unbound";
}
}