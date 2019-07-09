/*
 * ByteUtil.cpp
 *
 *  Created on: Jul 8, 2019
 *      Author: Nathan
 */

#include "ByteUtil.h"

namespace Minecraft {
	void encodeBytes(unsigned char* dst, unsigned char& offset, unsigned char* src, unsigned char src_size) {
		for (unsigned char i = offset; i < offset + src_size; i++) {
			dst[i] = src[i - offset];
		}
		offset += src_size; //Update offset!
	}

	void encodeShort(unsigned char* buffer, unsigned char& offset, unsigned short int value) {
		buffer[offset++] = (unsigned char)((value & 0xff00) >> 8);
		buffer[offset++] = (unsigned char)((value & 0x00ff));
	}

	void encodeInt(unsigned char* buffer, unsigned char& offset, unsigned long int value) {
		buffer[offset++] = (unsigned char)((value & 0xff000000UL) >> 24);
		buffer[offset++] = (unsigned char)((value & 0x00ff0000UL) >> 16);
		buffer[offset++] = (unsigned char)((value & 0x0000ff00UL) >> 8);
		buffer[offset++] = (unsigned char)((value & 0x000000ffUL));
	}

	void encodeLong(unsigned char* buffer, unsigned char& offset, unsigned long long int value) {
		buffer[offset++] = (unsigned char)((value & 0xff00000000000000ULL) >> 56);
		buffer[offset++] = (unsigned char)((value & 0x00ff000000000000ULL) >> 48);
		buffer[offset++] = (unsigned char)((value & 0x0000ff0000000000ULL) >> 40);
		buffer[offset++] = (unsigned char)((value & 0x000000ff00000000ULL) >> 32);
		buffer[offset++] = (unsigned char)((value & 0x00000000ff000000ULL) >> 24);
		buffer[offset++] = (unsigned char)((value & 0x0000000000ff0000ULL) >> 16);
		buffer[offset++] = (unsigned char)((value & 0x000000000000ff00ULL) >> 8);
		buffer[offset++] = (unsigned char)((value & 0x00000000000000ffULL));
	}

}
