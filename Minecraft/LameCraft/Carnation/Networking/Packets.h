#pragma once
#include "ByteUtil.h"
#include "VarInt.h"
#include <string.h>

namespace Minecraft {

	enum ConnectionStates {
		CONNECTION_STATE_HANDSHAKE,
		CONNECTION_STATE_STATUS,
		CONNECTION_STATE_LOGIN,
		CONNECTION_STATE_PLAY,
	};

	unsigned char* handshake_packet(unsigned long int protocol_version, const char* ip_address, unsigned short int server_port, ConnectionStates next_state, unsigned char& size);

	unsigned char* login_start(const char* username, unsigned char& size);

}