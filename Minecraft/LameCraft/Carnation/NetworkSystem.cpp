#include "NetworkSystem.h"
#include "Protocol/VarInt.h"
namespace Minecraft {
	NetworkSystem::NetworkSystem()
	{
		sock = 0;
	}
	void NetworkSystem::Init()
	{
		//We need to load some basic kernel modules in order to use networking features
		sceUtilityLoadNetModule(PSP_NET_MODULE_COMMON); //All sceNetCommands
		sceUtilityLoadNetModule(PSP_NET_MODULE_INET); //All sceInetCommands (including the socket library)
		sceUtilityLoadNetModule(PSP_NET_MODULE_SSL); //Unused, but you can use SSL functions if you need.

		//Result stores our codes from the initialization process
		int result = 0;

		result = sceNetInit(128 * 1024, 42, 0, 42, 0); //Creates the network manager with a buffer
		if (result < 0) { //These If Blocks close the game on an error
			sceKernelExitGame();
		}

		result = sceNetInetInit(); //Initializes Inet
		if (result < 0) {
			sceKernelExitGame();
		}

		result = sceNetApctlInit(0x10000, 48); //Initializes Access Point Control
		if (result < 0) {
			sceKernelExitGame();
		}

		result = sceNetResolverInit(); //Initializes DNS resolver (unused)
		if (result < 0) {
			sceKernelExitGame();
		}

		result = sceNetApctlConnect(1);	//Connects to your first (primary) internet connection.

		//Displays connection status
		int err;
		while (1) {
			int state;
			err = sceNetApctlGetState(&state);
			if (err != 0)
			{
				break;
			}
			if (state == 4)
				break;  // connected!

			sceKernelDelayThread(1000 * 50); //50 MS Delay;
		}

		SceNetApctlInfo info;
		sceNetApctlGetInfo(PSP_NET_APCTL_INFO_IP, &info);
	}
	void NetworkSystem::Connect(const char* address)
	{
		//Streaming Socket
		sock = socket(PF_INET, SOCK_STREAM, 0);
		struct sockaddr_in name;

		name.sin_family = AF_INET;
		name.sin_port = htons(25565); //Default Port
		inet_pton(AF_INET, address, &name.sin_addr.s_addr);
		connect(sock, (struct sockaddr*)& name, sizeof(name)); //Full connection!
	}
	void NetworkSystem::Disconnect()
	{
		close(sock);
	}
	void NetworkSystem::SendPacket(unsigned char* buffer, unsigned short size)
	{
		send(sock, buffer, size, 0);
	}

	int NetworkSystem::read(unsigned char* buffer, unsigned short buffLen) {
		short totalReceived = 0;
		while (buffLen > totalReceived) {
			int received = recv(sock, (char*)(buffer + totalReceived), (buffLen - totalReceived), 0);
			if (received <= 0)
				return -1; //ERROR
			totalReceived += received;
		}
		return 0;
	}

	long int NetworkSystem::readVarInt() {
		unsigned char data[MAX_VARINT_LENGTH];

		int dataLen = 0;
		do {
			read(&data[dataLen], 1);
		} while ((data[dataLen++] & 0x80) != 0);

		return decode_unsigned_varint(data, dataLen);
	}

	long long int NetworkSystem::readVarLong() {
		unsigned char data[MAX_VARLONG_LENGTH];

		int dataLen = 0;
		do {
			read(&data[dataLen], 1);
		} while ((data[dataLen++] & 0x80) != 0);

		return decode_unsigned_varlong(data, dataLen);
	}

	void NetworkSystem::ReceivePacket()
	{
		unsigned short length = readVarInt(); //Our length
		unsigned char* buffer = new unsigned char[length];
		int res = read(buffer, length);
		UnparsedPacket* packet = new UnparsedPacket();
		packet->size = length;
		packet->buffer = buffer;
		if (res == 0) {
			unparsed_packets.push(packet);
		}
	}

	NetworkSystem* g_NetworkManager;
}