#pragma once
#include <mclib/mclib.h>
#include <mclib/common/Vector.h>
#include <mclib/core/PlayerManager.h>

namespace Minecraft {
	namespace Client {
		class Player : public mc::core::PlayerListener {
		public:
			Player();
			~Player();

			void Init(mc::Vector3d pos, float y, float p);
			void Cleanup();

			void SetPosition(mc::Vector3d pos);
			void SetLook(float y, float p);

			inline void SetVelocity(mc::Vector3d vel) {
				velocity = vel;
			}
			inline void SetAcceleration(mc::Vector3d acc) {
				acceleration = acc;
			}

			void Update(float dt);

			void Draw();

			void OnClientSpawn(mc::core::PlayerPtr player);

			inline bool isSneaking() {
				return sneak;
			}

			inline bool isSprinting() {
				return sprint;
			}

			inline bool isOnGround() {
				return onGround;
			}

			inline mc::Vector3d getPosition() {
				return position;
			}

			inline float getYaw() {
				return yaw;
			}

			inline float getPitch() {
				return pitch;
			}

		private:
			float yaw, pitch, orientation; //In degrees!
			mc::Vector3d position, velocity, acceleration;
			bool onGround;
			bool sneak, sprint;


		};
	}
}