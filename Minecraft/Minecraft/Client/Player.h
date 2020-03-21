#pragma once
#include <pspgum.h>
#include "World/World.h"
#include <Shadow/Graphics/Frustum.h>
#include <Shadow/Physics/AABB.h>


namespace Minecraft {
	namespace Client {
		class Player {
		public:
			Player();
			~Player();

			void Init(glm::vec3 pos, float y, float p);
			void Cleanup();

			void SetPosition(glm::vec3 pos);
			void SetLook(float y, float p);

			inline void SetVelocity(glm::vec3 vel) {
				velocity = vel;
			}
			inline void SetAcceleration(glm::vec3 acc) {
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

			inline glm::vec3 getPosition() {
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

			inline ViewFrustum getFrustum(){
				return m_Frustum;
			}

			ScePspFMatrix4 projMatrix;
			ScePspFMatrix4 orthMatrix;
			ScePspFMatrix4 viewMatrix;
			ScePspFMatrix4 viewPreMatrix;
			ScePspFMatrix4 projViewMatrix;
			AABB boundingBox;

		private:
			float yaw, pitch, orientation; //In degrees!
			glm::vec3 position, velocity, acceleration;
			bool onGround;
			bool sneak, sprint;

			ViewFrustum m_Frustum;
			float tilt; //Extra

			int currBlock;

			bool changingFOV;
			bool flyEnabled;
			float fovChange;
		};
	}
}