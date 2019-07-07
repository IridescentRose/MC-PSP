#pragma once

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <string.h>
#include <pspnet.h>
#include <psputility.h>
#include <pspnet_inet.h>
#include <pspnet_apctl.h>
#include <pspnet_resolver.h>
#include <psphttp.h>
#include <pspsdk.h>
#include <pspwlan.h>
#include <sys/socket.h>
#include <unistd.h> 

namespace Minecraft {
	class NetworkSystem {
	public:
		NetworkSystem();
		void Init();
		void Connect(const char* address);
		void Disconnect();

		void SendPacket(unsigned char* buffer, unsigned short size);
	private:
		int sock;
	};
}