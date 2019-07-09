/*
 * ByteUtil.h
 *
 *  Created on: Jul 8, 2019
 *      Author: Nathan
 */

#pragma once

namespace Minecraft {
	void encodeBytes(unsigned char* dst, unsigned char& offset, unsigned char* src, unsigned char src_size);
	void encodeShort(unsigned char* buffer, unsigned char& offset, unsigned short int value);
	void encodeInt(unsigned char* buffer, unsigned char& offset, unsigned long int value);
	void encodeLong(unsigned char* buffer, unsigned char& offset, unsigned long long int value);
}
