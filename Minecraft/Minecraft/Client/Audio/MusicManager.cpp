#include "MusicManager.h"
#include <Utilities/Logger.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>


namespace Minecraft::Audio {
	RandomMusicGenerator::RandomMusicGenerator()
	{
		timeUntilNext = 0;
		clip = NULL;
	}
	RandomMusicGenerator::~RandomMusicGenerator()
	{

	}
	void RandomMusicGenerator::Init()
	{
		srand(time(NULL));
		timeUntilNext = rand() % 800 + 201;
	}
	void RandomMusicGenerator::Cleanup()
	{
		if(clip != NULL){
			clip->Stop();
			delete clip;
		}
	}
	void RandomMusicGenerator::FixedUpdate()
	{
		if (timeUntilNext <= 0) {
			//PLAY RANDOM
			
			if (clip != NULL) {
				clip->Stop();
				delete clip;
			}

			int choice = rand() % 4;

			int maxLim = 0;
			
			std::string path = "assets/sounds/music/game/";

			switch (choice) {
			case 0: {
				path += "hal";
				maxLim = 4;
				break;
			}
			case 1: {
				path += "nuance";
				maxLim = 2;
				break;
			}
			case 2: {
				path += "calm";
				maxLim = 3;
				break;
			}
			case 3: {
				path += "piano";
				maxLim = 3;
			}

			}

			int actualChoice = 1 + rand() % maxLim;
			path += std::to_string(actualChoice);
			path += ".bgm";

			clip = new AudioClip(path);
			clip->Play(7);

			srand(time(NULL));
			timeUntilNext = 6001 + (rand() % 2000);
		}
	}
}