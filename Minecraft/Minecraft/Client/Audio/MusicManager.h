#pragma once

#include <Audio/AudioClip.h>
using namespace Stardust::Audio;

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
		AudioClip* clip;
	};
}