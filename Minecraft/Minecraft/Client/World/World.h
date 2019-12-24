#pragma once
#include <pspkernel.h>
#include <Shadow/Utils/Timer.hpp>
#include "../Rendering/Sky.h"
#include "../Rendering/Sun.h"
#include "../Rendering/Moon.h"
#include "../Rendering/Stars.h"
#include "../Rendering/Clouds.h"
#include "../Audio/MusicManager.h"


#include "../Player.h"
#include "Chunk.h"
#include "BlockData.h"

using namespace Shadow::Utils;

namespace Minecraft::Client {

	struct TickTime {
		s64 worldAge;
		s64 time;
	};

	class World {
	public:
		World();
		~World();

		void Init();
		void Cleanup();
		
		void Update(float dt);
		void FixedUpdate(); //OnTick events
		void Draw();

		Timer tickTimer;
		Terrain::ChunkManager* chunkMan;
		Player* p;
		float fps;

	private:
		TickTime* timeData;
		SceUID tickUpdateThread;
		SceUID chunkManagerThread;

		Rendering::Sun* sun;
		Rendering::Moon* moon;
		Rendering::Sky* sky;
		Rendering::Stars* stars;
		Rendering::Clouds* clouds;

		Audio::RandomMusicGenerator* rmg;

		

		static int tickUpdate(SceSize args, void* argp);
		static int chunkManagement(SceSize args, void* argp);

	};

	extern World* g_World;
}