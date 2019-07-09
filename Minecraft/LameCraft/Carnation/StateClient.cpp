#include "StateClient.h"

#include "../Menu/LoadingScreen.h"
#include <Aurealis/Graphics/RenderManager.h>
#include <Aurealis/System/SystemManager.h>
#include "../World/Data/SharedTextureData.h"
#include <Aurealis/System/SystemManager.h>
#include "Protocol/Packets.h"
#include "Protocol/ProtocolDef.h"
using namespace Aurealis::System;

namespace Minecraft {
	StateClient::StateClient()
	{
		g_NetworkManager = 0;
	}
	void StateClient::Init()
	{
		g_TextureData.Init();
		g_NetworkManager = new NetworkSystem();
		g_NetworkManager->Init();


		//GET ADDRESS
		char ipAddr[15]; //192.168.000.111 (Size is 15)

		unsigned short test[15];
		unsigned short opis[14] = { 'S','e','r','v','e','r',' ','a','d','d', 'r', 'e', 's', 's' };
		if (g_System.ShowOSK(opis, test, 15) != -1)
		{
			std::string ipaddrenew = "";
			for (int j = 0; test[j]; j++)
			{
				unsigned c = test[j];

				if (32 <= c && c <= 127) // print ascii only
					ipaddrenew += c;
			}

			sprintf(ipAddr, "%s", ipaddrenew.c_str());
		}

		ip_length = strlen(ipAddr);

		//GET USER
		char username[16]; //Max length

		unsigned short test2[16];
		unsigned short opis2[8] = {'U', 's', 'e', 'r', 'n', 'a', 'm', 'e'};
		if (g_System.ShowOSK(opis2, test2, 16) != -1)
		{
			std::string usernew = "";
			for (int j = 0; test2[j]; j++)
			{
				unsigned c = test2[j];

				if (32 <= c && c <= 127) // print ascii only
					usernew += c;
			}

			sprintf(username, "%s", usernew.c_str());
		}

		user_length = strlen(username);

		g_NetworkManager->Connect(ipAddr);


		//HANDSHAKE
		unsigned char size;
		unsigned char* buffer = handshake_packet(MINECRAFT_PROTOCOL_VERSION_NUMBER, ipAddr, MINECRAFT_DEFAULT_PORT, CONNECTION_STATE_LOGIN, size);

		g_NetworkManager->SendPacket(buffer, size);
		delete[] buffer;

		buffer = login_start(username, size);
		g_NetworkManager->SendPacket(buffer, size);
		delete[] buffer;
		
	}
	void StateClient::Enter()
	{
	}
	void StateClient::CleanUp()
	{
	}
	void StateClient::Pause()
	{
	}
	void StateClient::Resume()
	{
	}
	void StateClient::HandleEvents(StateManager* sManager)
	{
		//HANDLE PACKETS HERE
	}
	void StateClient::Update(StateManager* sManager)
	{
	}

	void StateClient::Draw(StateManager* sManager)
	{
		g_RenderManager.StartFrame(1.0f, 1.0f, 1.0f);
		g_RenderManager.CleanBuffers();

		//RENDER STUFF
		g_NetworkManager->ReceivePacket();

		//DEVMODE
		if (true) {
			g_RenderManager.SetFontStyle(0.5, 0xFFFFFFFF, 0, 0x00000000);
			/*DEBUG STATS*/
			

			u32 freeMemory = Aurealis::System::g_System.freeMemory();
			//FPS HERE!
			g_RenderManager.DebugPrint(4, 14, "cpu: %d%%", g_RenderManager.GetCpuUsage());
			g_RenderManager.DebugPrint(4, 24, "gpu: %d%%", g_RenderManager.GetGpuUsage());
			g_RenderManager.DebugPrint(4, 34, "free memory: %.3f kb (%.3f mb)", (float)freeMemory / 1024.0f, ((float)freeMemory / 1024.0f) / 1024.0f);
			g_RenderManager.DebugPrint(4, 44, "packets received: %d", g_NetworkManager->unparsed_packets.size());
		}
		g_RenderManager.EndFrame();
	}
}