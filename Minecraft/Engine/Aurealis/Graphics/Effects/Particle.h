#pragma once

#include <Aurealis/Math/Vector3.h>
#include <Aurealis/Graphics/Vertex.h>
#include <pspmath.h>
#include <LameCraft/World/CraftWorld2.h>
#include <math.h>
#include <psptypes.h>
#include <string>
#include <Aurealis/Graphics/TextureUtil.h>

namespace Aurealis
{
	namespace Graphics
	{
		class Particle
		{
		public:

			Particle(CraftWorld* world, std::string _name, Vector3 _position);
			virtual ~Particle();

			void Update(CraftWorld* crtf, float dt);
			void Render(Frustum &camFrustum);

			bool CheckCollision(CraftWorld* crtf);

			void SetVelocity(Vector3 _velocity);
			void SetFramesAmount(int _totalFrames);
			void SetScale(float scale);
			void SetScale(float minScale, float maxScale);

            void SetMaxLiveTime(int _maxLiveTime);
            void SetLiveTime(int _liveTime); // in milisecs
            void SetLiveTime(int minLiveTime, int maxLiveTime); // in milisecs
            void SetGravity(float _gravity);
            void SetColor(Vector3 _color);
            void SetBrightness(float brightness);
            void SetBrightness(float minBrightness, float maxBrightness);

			void BuildVerticies();
			void BuildVerticiesForBlockCrack(CraftWorld* crtf, int blockId);
			void BuildVerticiesForItemCrack(CraftWorld* crtf, int itemId);

			Vector3 position;
			Vector3 velocity;

			bool toDestroy;
            float friction;

            // additional vars
            int var1;
            int var2;
            int var3;

            float varf1;
            float varf2;

		private:

		    TexturedVertex *particleVertices;

			float horizontalScale;
			float verticalScale;
			Texture* texture;

			float timeToLive;
			float maxTimeToLive;
			int frame;
			int totalFrames;

			Vector3 color;

			float gravity;
			float myLight;
			bool rederMe;

			std::string name;
			BoundingBox bBox;
		};
	}
}
