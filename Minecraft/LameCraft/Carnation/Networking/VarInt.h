#pragma once

namespace Minecraft {

	int encode_unsigned_varlong(unsigned long long int value, unsigned char* buffer);
	int encode_signed_varlong(signed long long int value, unsigned char* buffer);
	

	int encode_unsigned_varint(unsigned long int value, unsigned char* buffer);
	int encode_signed_varint(int value, unsigned char* buffer);
	

	unsigned long long int decode_unsigned_varlong(const unsigned char* const data, int& decoded_bytes);
	unsigned long int decode_unsigned_varint(const unsigned char* const data, int& decoded_bytes);
	
}