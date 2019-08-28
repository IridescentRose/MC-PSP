#include "Controls.hpp"
#include <sys/stat.h>
#include <fstream>

namespace Minecraft::Common{
Controls g_Control = {	PSP_SELECT,
						PSP_LEFT_TRIGGER,
						PSP_RIGHT_TRIGGER,
						PSP_ANALOG_LEFT,
						PSP_ANALOG_RIGHT,
						PSP_ANALOG_UP,
						PSP_ANALOG_DOWN,
                        PSP_SQUARE,
                        PSP_CIRCLE,
                        PSP_TRIANGLE,
                        PSP_CROSS,
						PSP_LEFT,
						PSP_RIGHT,
						PSP_UP,
						PSP_DOWN,
						PSP_START};

void loadControls()
{
	struct stat buffer;
	if (stat("controls.txt", &buffer) == 0) {
		std::ifstream file("controls.txt");
		
		file >> g_Control.jump;
		file >> g_Control.destroy;
		file >> g_Control.place;
		file >> g_Control.walkLeft;
		file >> g_Control.walkRight;
		file >> g_Control.walkUp;
		file >> g_Control.walkDown;
		file >> g_Control.lookLeft;
		file >> g_Control.lookRight;
		file >> g_Control.lookUp;
		file >> g_Control.lookDown;
		file >> g_Control.hotLeft;
		file >> g_Control.hotRight;
		file >> g_Control.toggleSprint;
		file >> g_Control.toggleCrouch;
		file >> g_Control.pauseMenu;
		file.close();
	}
	else {
		std::ofstream file("controls.txt");

		//Since the file doesn't exist, we use the preloaded defaults.

		//Write the default to a file
		file << g_Control.jump << std::endl;
		file << g_Control.destroy << std::endl;
		file << g_Control.place << std::endl;
		file << g_Control.walkLeft << std::endl;
		file << g_Control.walkRight << std::endl;
		file << g_Control.walkUp << std::endl;
		file << g_Control.walkDown << std::endl;
		file << g_Control.lookLeft << std::endl;
		file << g_Control.lookRight << std::endl;
		file << g_Control.lookUp << std::endl;
		file << g_Control.lookDown << std::endl;
		file << g_Control.hotLeft << std::endl;
		file << g_Control.hotRight << std::endl;
		file << g_Control.toggleSprint << std::endl;
		file << g_Control.toggleCrouch << std::endl;
		file << g_Control.pauseMenu << std::endl;

		file.close();
	}
	
}

void writeControls() 
{
	std::ofstream file("controls.txt");

	file << g_Control.jump << std::endl;
	file << g_Control.destroy << std::endl;
	file << g_Control.place << std::endl;
	file << g_Control.walkLeft << std::endl;
	file << g_Control.walkRight << std::endl;
	file << g_Control.walkUp << std::endl;
	file << g_Control.walkDown << std::endl;
	file << g_Control.lookLeft << std::endl;
	file << g_Control.lookRight << std::endl;
	file << g_Control.lookUp << std::endl;
	file << g_Control.lookDown << std::endl;
	file << g_Control.hotLeft << std::endl;
	file << g_Control.hotRight << std::endl;
	file << g_Control.toggleSprint << std::endl;
	file << g_Control.toggleCrouch << std::endl;
	file << g_Control.pauseMenu << std::endl;
	file.close();
}
}