#include "Player.h"
#include <Shadow/Utils/Logger.h>

using namespace Shadow::Utils;

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
		}
		
		Player::~Player()
		{
		}
		
		void Player::Init(mc::Vector3d pos, float y, float p)
		{
			position = pos;
			yaw = y;
			pitch = p;

			sneak = false;
			sprint = false;
			onGround = true;
		}
		void Player::Cleanup()
		{
		}

		void Player::OnClientSpawn(mc::core::PlayerPtr player) {
			Logging::log("Handling Spawn!", Logging::LOGGER_LEVEL_TRACE);
			position = player->GetEntity()->GetPosition();
			velocity = mc::Vector3d();
			acceleration = mc::Vector3d();
			orientation = player->GetEntity()->GetYaw();
			yaw = orientation;
			pitch = player->GetEntity()->GetHeadPitch();

			Logging::log("Handled Spawn!", Logging::LOGGER_LEVEL_TRACE);
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
			//UPDATE BASED ON INPUT!
			position.x += dt;
		}
		
		void Player::Draw()
		{
			//DRAW GUI STUFF
		}
	}
}