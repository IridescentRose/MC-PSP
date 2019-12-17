#include "Player.h"
#include <Shadow/Utils/Logger.h>
#include <Shadow/Graphics/RenderManager.h>
#include "../Common/Options.hpp"
#include <Shadow/System/Input.h>
#include <pspmath.h>

#define DEGTORAD(angleDegrees) ((angleDegrees) * 3.14159 / 180.0)


using namespace Shadow::System;
using namespace Shadow::Utils;
using namespace Shadow::Graphics;

namespace Minecraft {
	namespace Client {
		Player::Player()
		{
			position = { 0, 0, 0 };
			yaw = 0;
			pitch = 0;
			sneak = false;
			sprint = false;
			onGround = true;
			tilt = 0;
			fovChange = 0;
			changingFOV = false;
		}
		
		Player::~Player()
		{
		}
		
		void Player::Init(mc::Vector3d pos, float y, float p)
		{
			position = pos;
			yaw = y;
			pitch = p;
			tilt = 0;

			sneak = false;
			sprint = false;
			onGround = true;

			sceGumMatrixMode(GU_PROJECTION);
			sceGumLoadIdentity();
			sceGumOrtho(0, 480, 0, 272, -30, 30);
			sceGumStoreMatrix(&orthMatrix);

			sceGumMatrixMode(GU_PROJECTION);
			sceGumLoadIdentity();
			sceGumPerspective(Common::g_OptionsManager.options.fov * 40 + 70, 480.0f / 272.0f, 0.1f, 768.0f);
			sceGumStoreMatrix(&projMatrix);


		}
		void Player::Cleanup()
		{
		}


		void Player::SetPosition(mc::Vector3d pos)
		{
			position = pos;
		}

		void Player::SetLook(float y, float p)
		{
			yaw = y;
			pitch = p;
		}

		void Player::Update(float dt)
		{
			Input::InputUpdate();


			float rotSpeed = 60.0f; //Speed at which to rotate per second

			if (Input::KeyPressed(PSP_CTRL_CROSS) || Input::KeyHold(PSP_CTRL_CROSS)) {
				pitch += rotSpeed * dt;
			}

			if (Input::KeyPressed(PSP_CTRL_TRIANGLE) || Input::KeyHold(PSP_CTRL_TRIANGLE)) {
				pitch -= rotSpeed * dt;
			}

			if (Input::KeyPressed(PSP_CTRL_SQUARE) || Input::KeyHold(PSP_CTRL_SQUARE)) {
				yaw -= rotSpeed * dt;
			}

			if (Input::KeyPressed(PSP_CTRL_CIRCLE) || Input::KeyHold(PSP_CTRL_CIRCLE)) {
				yaw += rotSpeed * dt;
			}

			if (yaw > 360) {
				yaw = 0;
			}
			if (yaw < 0) {
				yaw = 360;
			}
			
			float BOUND = 89.999f;
			
			if (pitch <= -BOUND) {
				pitch = -BOUND;
			}
			if (pitch >= BOUND) {
				pitch = BOUND;
			}

			//Update the Pre-View Matrix
			sceGumMatrixMode(GU_VIEW);
			sceGumLoadIdentity();
			ScePspFVector3 v = { DEGTORAD(pitch), DEGTORAD(yaw), DEGTORAD(tilt) };
			sceGumRotateXYZ(&v);
			
			sceGumStoreMatrix(&viewPreMatrix);

			float walkSpeed = 4.317;

			if (Input::KeyPressed(PSP_CTRL_UP)) {
				if(!sneak){
					sprint = !sprint;
					changingFOV = true;
				}
			}
			if (Input::KeyPressed(PSP_CTRL_DOWN)) {
				if (!sprint) {
					sneak = !sneak;
				}
			}

			if (changingFOV) {
				if (sprint) {
					fovChange += 150.0f * dt;
					if (fovChange > 15.0f) {
						fovChange = 15;
						changingFOV = false;
					}
				}
				else {
					fovChange -= 150.0f * dt;
					if (fovChange < 0) {
						fovChange = 0;
						changingFOV = false;
					}
				}

				//Only update with FOV modifier
				sceGumMatrixMode(GU_PROJECTION);
				sceGumLoadIdentity();
				sceGumPerspective(Common::g_OptionsManager.options.fov * 40 + 70 + fovChange, 480.0f / 272.0f, 0.1f, 768.0f);
				sceGumStoreMatrix(&projMatrix);

			}

			if (Input::GetAnalogY() > 0.4) {

				float s = walkSpeed;

				if (sprint) {
					s = 5.612;
				}
				if (sneak) {
					s = 1.317;
				}

				velocity.x -= vfpu_sinf(DEGTORAD(-yaw)) * s;
				velocity.z -= vfpu_cosf(DEGTORAD(-yaw)) * s;
			}

			if (Input::GetAnalogY() < -0.4) {
				velocity.x -= -vfpu_sinf(DEGTORAD(-yaw)) * walkSpeed;
				velocity.z -= -vfpu_cosf(DEGTORAD(-yaw)) * walkSpeed;
			}

			if (Input::GetAnalogX() < -0.4) {
				velocity.x += -vfpu_sinf(DEGTORAD((-yaw + 270))) * walkSpeed * 0.7;
				velocity.z += -vfpu_cosf(DEGTORAD((-yaw + 270))) * walkSpeed * 0.7;
			}

			if (Input::GetAnalogX() > 0.4) {
				velocity.x += -vfpu_sinf(DEGTORAD((-yaw - 270))) * walkSpeed * 0.7;
				velocity.z += -vfpu_cosf(DEGTORAD((-yaw - 270))) * walkSpeed * 0.7;
			}

			position += velocity * dt;

			velocity = { 0, 0, 0 };

			ScePspFVector3 pos = { (float)position.x, -(float)position.y, (float)position.z };
			sceGumTranslate(&pos);
			sceGumStoreMatrix(&viewMatrix);


		}
		
		void Player::Draw()
		{
			//DRAW GUI STUFF
		}
	}
}