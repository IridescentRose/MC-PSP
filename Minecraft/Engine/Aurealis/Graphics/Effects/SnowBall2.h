#pragma once

#include <Aurealis/Math/Vector3.h>
#include <Aurealis/Graphics/Vertex.h>
#include <pspmath.h>
#include <LameCraft/World/CraftWorld2.h>
#include <math.h>
#include <psptypes.h>

namespace Aurealis
{
	namespace Graphics
	{
		class SnowBall2
		{
		public:
			SnowBall2(float pos2x, float pos2y, float pos2z);
			~SnowBall2();

			void SetTexture(int texture);
			void SetVeloc(float verAngle, float horAngle);
			void Update(CraftWorld* crtf, float dt);
			bool CheckCollision(CraftWorld* crtf);

			void Render();

			Vector3 position;
			Vector3 velocity;

		private:

			Vertex *ballVertices;
			int textureNumber;
			float snowHScale;
			float snowVScale;

			float startSpeed;
		};
	}
}