#pragma once

#include <Shadow/Audio/AudioManager.hpp>
using namespace Shadow::Audio;

namespace Minecraft::Audio {
	class RandomMusicGenerator {
		
	public:
		RandomMusicGenerator();
		~RandomMusicGenerator();

		void Init();
		void Cleanup();

		void FixedUpdate();

		int timeUntilNext;
	private:
		OSL_SOUND* snd;
	};
}