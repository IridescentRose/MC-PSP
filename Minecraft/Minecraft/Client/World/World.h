#pragma once
#include <pspkernel.h>
#include <Utilities/Timer.h>
#include "../Rendering/Sky.h"
#include "../Rendering/Sun.h"
#include "../Rendering/Moon.h"
#include "../Rendering/Stars.h"
#include "../Rendering/Clouds.h"
#include "../Audio/MusicManager.h"
#include <Graphics/2D/SpriteBase.h>
#include "../../Menu/LoadingScreen.hpp"

#include "../Player.h"

/*
#include "Chunk.h"
#include <queue>
#include "BlockData.h"
*/

using namespace Stardust::Graphics;
using namespace Stardust::Graphics::Render2D;

namespace Minecraft::Client {
	class Player;
	
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

		void handleGM();

		void Save();

		Stardust::Utilities::Timer tickTimer;
		//Terrain::ChunkManager* chunkMan;
		Player* p;
		int fps;
		int frameCounter;
		float frameTimer;
	
		int gameMode;

		TickTime* timeData;
		volatile bool killReceived;
		volatile bool tUpReady;
		volatile bool cUpReady;
		volatile bool readyForKill;
	private:
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

		static int ChunkMan2(int z);

		int lastLevel;

		volatile bool genning;

		Sprite* crosshair;
		float animationTimer;
		int animationWaterFrame;
		int animationLavaFrame;
		bool animationLavaStep;

		Texture* textureWaterAnimationId, *textureLavaAnimationId;

	};

	extern World* g_World;
}