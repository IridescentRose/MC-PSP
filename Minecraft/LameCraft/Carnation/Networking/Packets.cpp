#include "Packets.h"
namespace Minecraft {
	unsigned char* handshake_packet(unsigned long int protocol_version, const char* ip_address, unsigned short int server_port, ConnectionStates next_state, unsigned char& size)
	{
		unsigned char protocol[5];
		unsigned char state[5];

		unsigned char protocolSize = encode_unsigned_varint(protocol_version, protocol);
		unsigned char stateSize = encode_unsigned_varint(next_state, state);
		unsigned char addressSize = (unsigned char)strlen(ip_address);
		unsigned char address[5];
		unsigned char addressSizeSize = encode_unsigned_varint(addressSize, address);

		size = 0;
		size = 3 + protocolSize + stateSize + addressSize + addressSizeSize;


		unsigned char* buffer = new unsigned char[size + 1];
		buffer[0] = size;
		size++; //Length byte
		buffer[1] = 0x00;
		unsigned char latest = 2;

		encodeBytes(buffer, latest, protocol, protocolSize);
		encodeBytes(buffer, latest, address, addressSizeSize);
		encodeBytes(buffer, latest, (unsigned char*)ip_address, addressSize);
		encodeShort(buffer, latest, server_port);
		encodeBytes(buffer, latest, state, stateSize);

		return buffer;
	}
	unsigned char* login_start(const char* username, unsigned char& size)
	{
		unsigned char userSize = (unsigned char)strlen(username);
		unsigned char user[5];
		unsigned char userSizeSize = encode_unsigned_varint(userSize, user);

		unsigned char* buffer = new unsigned char[userSize + 2 + userSizeSize];
		buffer[0] = userSize + userSizeSize + 1;
		buffer[1] = 0x00;
		unsigned char current = 2;
		encodeBytes(buffer, current, user, userSizeSize);
		encodeBytes(buffer, current, (unsigned char*)username, userSize);
		size = userSize + userSizeSize + 2;
		return buffer;
	}
}