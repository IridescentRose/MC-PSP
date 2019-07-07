#include "VarInt.h"

namespace Minecraft {

	int encode_unsigned_varlong(unsigned long long int value, unsigned char* buffer)
	{
		int encoded = 0;
		do
		{
			unsigned char next_byte = value & 0x7F;
			value >>= 7;
			if (value)
				next_byte |= 0x80;
			buffer[encoded++] = next_byte;
		} while (value);
		return encoded;
	}

	int encode_signed_varlong(signed long long int value, unsigned char* buffer)
	{
		unsigned long long int uvalue;
		uvalue = (unsigned long long int)(value < 0 ? ~(value << 1) : (value << 1));

		return encode_unsigned_varlong(uvalue, buffer);
	}

	int encode_unsigned_varint(unsigned long int value, unsigned char* buffer)
	{
		int encoded = 0;
		do
		{
			unsigned char next_byte = value & 0x7F;
			value >>= 7;
			if (value)
				next_byte |= 0x80;
			buffer[encoded++] = next_byte;
		} while (value);
		return encoded;
	}

	int encode_signed_varint(int value, unsigned char* buffer)
	{
		unsigned long int uvalue;
		uvalue = (unsigned long int)(value < 0 ? ~(value << 1) : (value << 1));

		return encode_unsigned_varint(uvalue, buffer);
	}

	unsigned long long int decode_unsigned_varlong(const unsigned char* const data, int& decoded_bytes)
	{
		int i = 0;
		unsigned long long int decoded_value = 0;
		int shift_amount = 0;

		do
		{
			decoded_value |= (unsigned long long int)(data[i] & 0x7F) << shift_amount;
			shift_amount += 7;
		} while ((data[i++] & 0x80) != 0);

		decoded_bytes = i;
		return decoded_value;
	}

	unsigned long int decode_unsigned_varint(const unsigned char* const data, int& decoded_bytes)
	{
		int i = 0;
		unsigned long int decoded_value = 0;
		int shift_amount = 0;

		do
		{
			decoded_value |= (unsigned long int)(data[i] & 0x7F) << shift_amount;
			shift_amount += 7;
		} while ((data[i++] & 0x80) != 0);

		decoded_bytes = i;
		return decoded_value;
	}
}