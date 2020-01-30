#pragma once
#include <pspkernel.h>
#include <Shadow/Utils/Timer.hpp>
#include "../Rendering/Sky.h"
#include "../Rendering/Sun.h"
#include "../Rendering/Moon.h"
#include "../Rendering/Stars.h"
#include "../Rendering/Clouds.h"
#include "../Audio/MusicManager.h"
#include <Shadow/Graphics/Sprite.h>

#include "../Player.h"
#include "Chunk.h"
#include <queue>
#include "BlockData.h"

using namespace Shadow::Utils;
using namespace Shadow::Graphics;

namespace Minecraft::Client {
	class Player;
	
	enum EventTypes{
		EVENT_TYPE_BREAK,
		EVENT_TYPE_PLACE
	};

	struct Event{
		int type;
	};

	struct BlockBreakEvent : Event {
		mc::Vector3d breakPositionAbsolute;
	};
	struct BlockPlaceEvent : Event {
		mc::Vector3d placePositionAbsolute;
		ChunkBlock blk;
	};

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

		std::queue<Event*> eventBus;
		TickTime* timeData;
		int xabcd;
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

		int lastLevel;

		static int DoChunkManagement();

		Sprite* crosshair;
		float animationTimer;
		int animationWaterFrame;
		int animationLavaFrame;
		bool animationLavaStep;

		Texture* textureWaterAnimationId, *textureLavaAnimationId;

	};

	extern World* g_World;
}