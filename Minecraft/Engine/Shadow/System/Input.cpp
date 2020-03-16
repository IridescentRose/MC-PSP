#include "Input.h"
#include <fstream>

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
		std::fstream file(name);

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
}