#include "Player.h"
#include <Graphics/RendererCore.h>
#include "../Common/Options.hpp"
#include <glm/glm.hpp>
#include <Utilities/Input.h>
#include <glm/gtx/rotate_vector.hpp>
#include <pspmath.h>
#include <iostream>
#include "World/World.h"
#define DEGTORAD(angleDegrees) ((angleDegrees) * 3.14159f / 180.0f)


using namespace Stardust::Utilities;
using namespace Stardust::Graphics;

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
			currBlock = 0;
			boundingBox.extent = {0.6f, 1.625f, 0.6f};
		}
		
		Player::~Player()
		{
		}
		
		void Player::Init(glm::vec3 pos, float y, float p)
		{
			position = pos;
			yaw = y;
			pitch = p;
			tilt = 0;

			sneak = false;
			sprint = false;
			onGround = true;
			flyEnabled = false;

			sceGumMatrixMode(GU_PROJECTION);
			sceGumLoadIdentity();
			sceGumOrtho(0, 480, 0, 272, -30, 30);
			sceGumStoreMatrix(&orthMatrix);

			sceGumMatrixMode(GU_PROJECTION);
			sceGumLoadIdentity();
			sceGumPerspective(Common::g_OptionsManager.options.fov * 40 + 70, 480.0f / 272.0f, 0.1f, 1000.0f);
			sceGumStoreMatrix(&projMatrix);


		}
		void Player::Cleanup()
		{
		}


		void Player::SetPosition(glm::vec3 pos)
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
			updateInputs();

			

			float rotSpeed = 120.0f; //Speed at which to rotate per second

			if (KeyHold(buttonFromAction("lookUp"))) {
				pitch -= rotSpeed * dt;
			}

			if (KeyHold(buttonFromAction("lookDown"))) {
				pitch += rotSpeed * dt;
			}

			if (KeyHold(buttonFromAction("lookLeft"))) {
				yaw -= rotSpeed * dt;
			}

			if ( KeyHold(buttonFromAction("lookRight"))) {
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

			if (KeyHold(buttonFromAction("sprint"))) {
				if(!sneak){
					sprint = !sprint;
					changingFOV = true;
				}
			}
			if (KeyHold(buttonFromAction("sneak"))) {
				if (!sprint) {
					sneak = !sneak;
				}
			}

			if(isFly()){
				sneak = false;
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
				sceGumPerspective(Common::g_OptionsManager.options.fov * 40 + 70 + fovChange, 480.0f / 272.0f, 0.1f, 256.0f);
				sceGumStoreMatrix(&projMatrix);

			}

			if (KeyHold(buttonFromAction("walkForward"))) {
				float s = walkSpeed;

				if (sprint) {
					s = 5.612;
				}
				if (sneak) {
					s = 1.317;
				}
				if(buttonFromAction("walkForward") == PSP_CTRL_ANALOG_X || buttonFromAction("walkForward") == PSP_CTRL_ANALOG_Y){
				    velocity.x += -vfpu_sinf(DEGTORAD(-yaw)) * s * dt * KeyStrength(buttonFromAction("walkForward"));
				    velocity.z += -vfpu_cosf(DEGTORAD(-yaw)) * s * dt * KeyStrength(buttonFromAction("walkForward"));
				}else{
					velocity.x += -vfpu_sinf(DEGTORAD(-yaw)) * s * dt;
					velocity.z += -vfpu_cosf(DEGTORAD(-yaw)) * s * dt;
				}

			}else if (KeyHold(buttonFromAction("walkBackward"))){
				if(buttonFromAction("walkBackward") == PSP_CTRL_ANALOG_X || buttonFromAction("walkBackward") == PSP_CTRL_ANALOG_Y){
				    velocity.x += -vfpu_sinf(DEGTORAD(-yaw)) * dt * KeyStrength(buttonFromAction("walkBackward"));
				    velocity.z += -vfpu_cosf(DEGTORAD(-yaw)) * dt * KeyStrength(buttonFromAction("walkBackward"));
				}else{
					velocity.x += vfpu_sinf(DEGTORAD(-yaw)) * walkSpeed * dt;
					velocity.z += vfpu_cosf(DEGTORAD(-yaw)) * walkSpeed * dt;	
				}
			}

			
			

			if (KeyHold(buttonFromAction("walkStrafeLeft"))) {
				if(buttonFromAction("walkStrafeLeft") == PSP_CTRL_ANALOG_X || buttonFromAction("walkStrafeLeft") == PSP_CTRL_ANALOG_Y){
					velocity.x += vfpu_sinf(DEGTORAD((-yaw + 270))) * walkSpeed * 0.7 * dt * KeyStrength(buttonFromAction("walkStrafeLeft"));;
					velocity.z += vfpu_cosf(DEGTORAD((-yaw + 270))) * walkSpeed * 0.7 * dt * KeyStrength(buttonFromAction("walkStrafeLeft"));;
				}else{
					velocity.x += vfpu_sinf(DEGTORAD((-yaw + 270))) * walkSpeed * 0.7 * dt;
					velocity.z += vfpu_cosf(DEGTORAD((-yaw + 270))) * walkSpeed * 0.7 * dt;
				}
			}
			if (KeyHold(buttonFromAction("walkStrafeRight"))) {
				if(buttonFromAction("walkStrafeRight") == PSP_CTRL_ANALOG_X || buttonFromAction("walkStrafeRight") == PSP_CTRL_ANALOG_Y){
					velocity.x += vfpu_sinf(DEGTORAD((-yaw + 270))) * walkSpeed * 0.7 * dt * KeyStrength(buttonFromAction("walkStrafeRight"));;
					velocity.z += vfpu_cosf(DEGTORAD((-yaw + 270))) * walkSpeed * 0.7 * dt * KeyStrength(buttonFromAction("walkStrafeRight"));;
				}else{
					velocity.x += -vfpu_sinf(DEGTORAD((-yaw + 270))) * walkSpeed * 0.7 * dt;
					velocity.z += -vfpu_cosf(DEGTORAD((-yaw + 270))) * walkSpeed * 0.7 * dt;
				}
			}

			if(flyEnabled){
				if(KeyHold(buttonFromAction("jump"))){
					//Fly upwards
					velocity.y += 5.812 * dt;
				}
				if(KeyHold(buttonFromAction("sneak"))){
					//Fly downwards
					velocity.y -= 4.317 *dt;
				}
			}else{
				velocity.y -= 28.0f * dt * dt;
				if(velocity.y > 90.0f * dt){
					velocity.y = 90.0f * dt;
				}
			}

			if(KeyPressed(buttonFromAction("break")) && KeyPressed(buttonFromAction("place"))){
				toggleFly();
			}



			if(g_World->gameMode != 3){
			glm::vec3 testPos = {(float)position.x, (float)position.y, (float)position.z};
			if(flyEnabled){
				testPos += velocity / 4.0f;
			}else{
				testPos += velocity;
			}

			if(g_World->chunkMan->getBlock((int)-testPos.x, (int)testPos.y, (int)-testPos.z).ID == 0 && g_World->chunkMan->getBlock((int)-testPos.x, (int)(testPos.y + 1.8f), (int)-testPos.z).ID == 0 && g_World->chunkMan->getBlock((int)-testPos.x, (int)(testPos.y + 0.9f), (int)-testPos.z).ID == 0 ){
				bool flag = true;
				
				if(g_World->chunkMan->getBlock((int)(-testPos.x + 0.2f), (int)(testPos.y), (int)(-testPos.z)).ID != 0){
					testPos.x = (float)((int)testPos.x - 1) + 0.2f;
					velocity.x = 0;
				}
				if(g_World->chunkMan->getBlock((int)(-testPos.x - 0.2f), (int)(testPos.y), (int)(-testPos.z)).ID != 0){
					testPos.x = (float)((int)testPos.x -1) + 0.8f;
					velocity.x = 0;
				}

				if(g_World->chunkMan->getBlock((int)(-testPos.x + 0.2f), (int)(testPos.y + 1.5f), (int)(-testPos.z)).ID != 0){
					testPos.x = (float)((int)testPos.x - 1) + 0.2f;
					velocity.x = 0;
				}
				if(g_World->chunkMan->getBlock((int)(-testPos.x - 0.2f), (int)(testPos.y + 1.5f), (int)(-testPos.z)).ID != 0){
					testPos.x = (float)((int)testPos.x -1) + 0.8f;
					velocity.x = 0;
				}


				if(g_World->chunkMan->getBlock((int)(-testPos.x), (int)(testPos.y), (int)(-testPos.z + 0.2f)).ID != 0){
					testPos.z = (float)((int)testPos.z - 1) + 0.2f;
					velocity.z = 0;
				}
				if(g_World->chunkMan->getBlock((int)(-testPos.x), (int)(testPos.y), (int)(-testPos.z - 0.2f)).ID != 0){
					testPos.z = (float)((int)testPos.z -1) + 0.8f;
					velocity.z = 0;
				}


				if(g_World->chunkMan->getBlock((int)(-testPos.x), (int)(testPos.y + 1.5f), (int)(-testPos.z + 0.2f)).ID != 0){
					testPos.z = (float)((int)testPos.z - 1) + 0.2f;
					velocity.z = 0;
				}
				if(g_World->chunkMan->getBlock((int)(-testPos.x), (int)(testPos.y + 1.5f), (int)(-testPos.z - 0.2f)).ID != 0){
					testPos.z = (float)((int)testPos.z -1) + 0.8f;
					velocity.z = 0;
				}


				if(flag)
					position = testPos;
				
			}else{
				velocity.y = 0.0f;

				testPos = {(float)position.x, (float)position.y, (float)position.z};
				testPos += velocity;

				if(g_World->chunkMan->getBlock((int)-testPos.x, (int)testPos.y, (int)-testPos.z).ID == 0 && g_World->chunkMan->getBlock((int)-testPos.x, (int)(testPos.y + 1.8f), (int)-testPos.z).ID == 0){
				bool flag = true;
				
				if(g_World->chunkMan->getBlock((int)(-testPos.x + 0.2f), (int)(testPos.y), (int)(-testPos.z)).ID != 0){
					testPos.x = (float)((int)testPos.x - 1) + 0.2f;
					velocity.x = 0;
				}
				if(g_World->chunkMan->getBlock((int)(-testPos.x - 0.2f), (int)(testPos.y), (int)(-testPos.z)).ID != 0){
					testPos.x = (float)((int)testPos.x -1) + 0.8f;
					velocity.x = 0;
				}

				if(g_World->chunkMan->getBlock((int)(-testPos.x + 0.2f), (int)(testPos.y + 1.5f), (int)(-testPos.z)).ID != 0){
					testPos.x = (float)((int)testPos.x - 1) + 0.2f;
					velocity.x = 0;
				}
				if(g_World->chunkMan->getBlock((int)(-testPos.x - 0.2f), (int)(testPos.y + 1.5f), (int)(-testPos.z)).ID != 0){
					testPos.x = (float)((int)testPos.x -1) + 0.8f;
					velocity.x = 0;
				}


				if(g_World->chunkMan->getBlock((int)(-testPos.x), (int)(testPos.y), (int)(-testPos.z + 0.2f)).ID != 0){
					testPos.z = (float)((int)testPos.z - 1) + 0.2f;
					velocity.z = 0;
				}
				if(g_World->chunkMan->getBlock((int)(-testPos.x), (int)(testPos.y), (int)(-testPos.z - 0.2f)).ID != 0){
					testPos.z = (float)((int)testPos.z -1) + 0.8f;
					velocity.z = 0;
				}


				if(g_World->chunkMan->getBlock((int)(-testPos.x), (int)(testPos.y + 1.5f), (int)(-testPos.z + 0.2f)).ID != 0){
					testPos.z = (float)((int)testPos.z - 1) + 0.2f;
					velocity.z = 0;
				}
				if(g_World->chunkMan->getBlock((int)(-testPos.x), (int)(testPos.y + 1.5f), (int)(-testPos.z - 0.2f)).ID != 0){
					testPos.z = (float)((int)testPos.z -1) + 0.8f;
					velocity.z = 0;
				}


				if(flag)
					position = testPos;
				}
			}


			if(KeyPressed(PSP_CTRL_SELECT) && !isFly() && velocity.y > -0.2f){
				velocity.y = 8.945f / 60.0f;

				// 1.25
				// 1.25 = 16.0f * t^2 + v0 * t
				// v = v - 32t
				// v0 = 32t 
				// v = 0

				// 1.25 = 16t^2 + 32t
				// 1.25 = 16t(t + 2)
				// 5 / 64 = t(t+2)
				//
			}

			if(!flyEnabled){
				velocity = {0.f, velocity.y, 0.f};
				
			}else{
				velocity *= 0.9f;
			}
			}else{
				position += velocity / 4.0f;
				velocity *= 0.9f;
			}


			ScePspFVector3 pos = { (float)position.x, -(float)position.y - 1.625f, (float)position.z };
			sceGumTranslate(&pos);
			sceGumStoreMatrix(&viewMatrix);

			if(KeyPressed(buttonFromAction("break"))){
				

				//RAY CAST

				glm::vec3 unitVec = glm::vec3(0, 0, -1);
				unitVec = glm::rotateX(unitVec, -pitch);
				unitVec = glm::rotateY(unitVec, -yaw);
				glm::normalize(unitVec);
				unitVec *= 0.25;

				glm::vec3 currVec = glm::vec3(-position.x, position.y + 1.625f, -position.z);
				glm::vec3 diffVec = glm::vec3(0, 0, 0);


				int numBlocks = 0;
				if(g_World->gameMode == 1){
					numBlocks = 20;
				}else{
					numBlocks = 18;
				}

				for(int i = 0; i < numBlocks; i++){
					
					currVec += unitVec;
					//Check if it hits a block
					ChunkBlock blk = g_World->chunkMan->getBlock((int)currVec.x, (int)currVec.y, (int)currVec.z);

					//If it hits something real...
					if(blk.ID != 0){
						
						BlockBreakEvent* e = new BlockBreakEvent();
						e->type = EVENT_TYPE_BREAK;
						e->breakPositionAbsolute = mc::Vector3d((int)currVec.x, (int)currVec.y, (int)currVec.z);
						g_World->eventBus.push(e);
						break;
					}
				}


			}
			
			if(KeyPressed(buttonFromAction("place"))){


				//RAY CAST

				glm::vec3 unitVec = glm::vec3(0, 0, -1);
				unitVec = glm::rotateX(unitVec, -pitch);
				unitVec = glm::rotateY(unitVec, -yaw);
				glm::normalize(unitVec);
				unitVec *= 0.25;

				glm::vec3 currVec = glm::vec3(-position.x, position.y + 1.625f, -position.z);
				glm::vec3 refVec = glm::vec3(-position.x, position.y, -position.z);
				glm::vec3 diffVec = glm::vec3(0, 0, 0);

				int numBlocks = 0;
				if(g_World->gameMode == 1){
					numBlocks = 20;
				}else{
					numBlocks = 18;
				}

				for(int i = 0; i < numBlocks; i++){
					
					currVec += unitVec;

					//Check if it hits a block
					ChunkBlock blk = g_World->chunkMan->getBlock((int)currVec.x, (int)currVec.y, (int)currVec.z);

					//If it hits something real...
					if(blk.ID != 0){
						glm::vec3 untrace = currVec;
						
						while((int) untrace.x == (int) currVec.x && (int) untrace.y == (int) currVec.y && (int) untrace.z == (int) currVec.z){
							untrace -= unitVec * 0.02f;
						}


						glm::vec3 currPos = {-(float)position.x, (float)position.y + 1.625f, -(float)position.z};
						if( (abs((untrace - currPos).x) > 0.81f || abs((untrace - currPos).z) > 0.81f) || ((untrace - currPos).y > 0.5f) || (untrace - currPos).y < -1.75f){
							BlockPlaceEvent* e = new BlockPlaceEvent();
							e->type = EVENT_TYPE_PLACE;
							e->placePositionAbsolute = mc::Vector3d((int)untrace.x, (int)untrace.y, (int)untrace.z);
							e->blk = BlockData::InstancePointer()->registered_blocks[currBlock];
							g_World->eventBus.push(e);
						}
						break;
						

					}
				}
			}

			if(KeyPressed(buttonFromAction("hotbarLeft"))){
				currBlock--;
				if(currBlock < 0){
					currBlock = BlockData::InstancePointer()->registered_blocks.size() - 1;
				}
			}

			if(KeyPressed(buttonFromAction("hotbarRight"))){
				currBlock++;
				if(currBlock == BlockData::InstancePointer()->registered_blocks.size()){
					currBlock = 0;
				}
			}

			glm::mat4 p = glm::perspective(Common::g_OptionsManager.options.fov * 40 + 70 + fovChange, 480.0f / 272.0f, 0.1f, 256.0f);
			glm::mat4 vie = glm::mat4(1);
			
			vie = glm::rotate(vie, pitch, {1, 0, 0});
			vie = glm::rotate(vie, yaw, {0, 1, 0});
			vie = glm::translate(vie, {pos.x, pos.y, pos.z});

			m_Frustum.update(p * vie);

		}
		
		void Player::Draw()
		{
			//DRAW GUI STUFF
		}
	}
}