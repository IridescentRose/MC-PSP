#pragma once
#include <mclib/mclib.h>
#include <mclib/common/Vector.h>
#include <pspgum.h>

namespace Minecraft {
	namespace Client {
		class Player {
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

			inline void toggleFly(){
				flyEnabled = !flyEnabled;
			}

			inline bool isFly(){
				return flyEnabled;
			}

			ScePspFMatrix4 projMatrix;
			ScePspFMatrix4 orthMatrix;
			ScePspFMatrix4 viewMatrix;
			ScePspFMatrix4 viewPreMatrix;
			ScePspFMatrix4 projViewMatrix;

		private:
			float yaw, pitch, orientation; //In degrees!
			mc::Vector3d position, velocity, acceleration;
			bool onGround;
			bool sneak, sprint;
			float tilt; //Extra

			bool changingFOV;
			bool flyEnabled;
			float fovChange;
		};
	}
}