/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 2018 - 2019, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
#include "curlcheck.h"

#include "x509asn1.h"

static CURLcode unit_setup(void)
{
  return CURLE_OK;
}

static void unit_stop(void)
{

}
#if defined(USE_GSKIT) || defined(USE_NSS) || defined(USE_GNUTLS) || \
    defined(USE_WOLFSSL) || defined(USE_SCHANNEL)

/* cert captured from gdb when connecting to curl.haxx.se on October 26
   2018 */
static unsigned char cert[] = {
  0x30, 0x82, 0x0F, 0x5B, 0x30, 0x82, 0x0E, 0x43, 0xA0, 0x03, 0x02, 0x01, 0x02,
  0x02, 0x0C, 0x08, 0x77, 0x99, 0x2C, 0x6B, 0x67, 0xE1, 0x18, 0xD6, 0x66, 0x66,
  0x9E, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01,
  0x0B, 0x05, 0x00, 0x30, 0x57, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04,
  0x06, 0x13, 0x02, 0x42, 0x45, 0x31, 0x19, 0x30, 0x17, 0x06, 0x03, 0x55, 0x04,
  0x0A, 0x13, 0x10, 0x47, 0x6C, 0x6F, 0x62, 0x61, 0x6C, 0x53, 0x69, 0x67, 0x6E,
  0x20, 0x6E, 0x76, 0x2D, 0x73, 0x61, 0x31, 0x2D, 0x30, 0x2B, 0x06, 0x03, 0x55,
  0x04, 0x03, 0x13, 0x24, 0x47, 0x6C, 0x6F, 0x62, 0x61, 0x6C, 0x53, 0x69, 0x67,
  0x6E, 0x20, 0x43, 0x6C, 0x6F, 0x75, 0x64, 0x53, 0x53, 0x4C, 0x20, 0x43, 0x41,
  0x20, 0x2D, 0x20, 0x53, 0x48, 0x41, 0x32, 0x35, 0x36, 0x20, 0x2D, 0x20, 0x47,
  0x33, 0x30, 0x1E, 0x17, 0x0D, 0x31, 0x38, 0x31, 0x30, 0x32, 0x32, 0x31, 0x37,
  0x31, 0x38, 0x32, 0x31, 0x5A, 0x17, 0x0D, 0x31, 0x39, 0x30, 0x33, 0x32, 0x31,
  0x31, 0x33, 0x34, 0x33, 0x34, 0x34, 0x5A, 0x30, 0x77, 0x31, 0x0B, 0x30, 0x09,
  0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x13, 0x30, 0x11,
  0x06, 0x03, 0x55, 0x04, 0x08, 0x0C, 0x0A, 0x43, 0x61, 0x6C, 0x69, 0x66, 0x6F,
  0x72, 0x6E, 0x69, 0x61, 0x31, 0x16, 0x30, 0x14, 0x06, 0x03, 0x55, 0x04, 0x07,
  0x0C, 0x0D, 0x53, 0x61, 0x6E, 0x20, 0x46, 0x72, 0x61, 0x6E, 0x63, 0x69, 0x73,
  0x63, 0x6F, 0x31, 0x15, 0x30, 0x13, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x0C, 0x0C,
  0x46, 0x61, 0x73, 0x74, 0x6C, 0x79, 0x2C, 0x20, 0x49, 0x6E, 0x63, 0x2E, 0x31,
  0x24, 0x30, 0x22, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x1B, 0x6A, 0x32, 0x2E,
  0x73, 0x68, 0x61, 0x72, 0x65, 0x64, 0x2E, 0x67, 0x6C, 0x6F, 0x62, 0x61, 0x6C,
  0x2E, 0x66, 0x61, 0x73, 0x74, 0x6C, 0x79, 0x2E, 0x6E, 0x65, 0x74, 0x30, 0x82,
  0x01, 0x22, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01,
  0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0F, 0x00, 0x30, 0x82, 0x01, 0x0A,
  0x02, 0x82, 0x01, 0x01, 0x00, 0xC2, 0x72, 0xA2, 0x4A, 0xEF, 0x26, 0x42, 0xD7,
  0x85, 0x74, 0xC9, 0xB4, 0x9F, 0xE3, 0x31, 0xD1, 0x40, 0x77, 0xC9, 0x4B, 0x4D,
  0xFE, 0xC8, 0x75, 0xF3, 0x32, 0x76, 0xAD, 0xF9, 0x08, 0x22, 0x9E, 0xFA, 0x2F,
  0xFE, 0xEC, 0x6C, 0xC4, 0xF5, 0x1F, 0x70, 0xC9, 0x8F, 0x07, 0x48, 0x31, 0xAD,
  0x75, 0x18, 0xFC, 0x06, 0x5A, 0x4F, 0xDD, 0xFD, 0x05, 0x39, 0x6F, 0x22, 0xF9,
  0xAD, 0x62, 0x1A, 0x9E, 0xA6, 0x16, 0x48, 0x75, 0x8F, 0xB8, 0x07, 0x18, 0x25,
  0x1A, 0x87, 0x30, 0xB0, 0x3C, 0x6F, 0xE0, 0x9D, 0x90, 0x63, 0x2A, 0x16, 0x1F,
  0x0D, 0x10, 0xFC, 0x06, 0x7E, 0xEA, 0x51, 0xE2, 0xB0, 0x6D, 0x42, 0x4C, 0x2C,
  0x59, 0xF4, 0x6B, 0x99, 0x3E, 0x82, 0x1D, 0x08, 0x04, 0x2F, 0xA0, 0x63, 0x3C,
  0xAA, 0x0E, 0xE1, 0x5D, 0x67, 0x2D, 0xB3, 0xF4, 0x15, 0xD6, 0x16, 0x4E, 0xAA,
  0x91, 0x45, 0x6B, 0xC5, 0xA6, 0xED, 0x83, 0xAF, 0xF1, 0xD7, 0x42, 0x5E, 0x9B,
  0xC8, 0x39, 0x0C, 0x06, 0x76, 0x7A, 0xB8, 0x3E, 0x16, 0x70, 0xF5, 0xEB, 0x8B,
  0x33, 0x5A, 0xA9, 0x03, 0xED, 0x79, 0x0E, 0xAD, 0xBB, 0xC4, 0xF8, 0xDA, 0x93,
  0x53, 0x2A, 0xC4, 0xC9, 0x1A, 0xD1, 0xC3, 0x44, 0xD7, 0xC6, 0xD0, 0xC6, 0xAC,
  0x13, 0xE3, 0xB5, 0x73, 0x3A, 0xDF, 0x54, 0x15, 0xFB, 0xB4, 0x6B, 0x36, 0x39,
  0x18, 0xB5, 0x61, 0x12, 0xF0, 0x37, 0xAB, 0x81, 0x5F, 0x0C, 0xE7, 0xDF, 0xC1,
  0xC5, 0x5E, 0x99, 0x67, 0x85, 0xFF, 0xAD, 0xD6, 0x82, 0x09, 0x1F, 0x27, 0xE5,
  0x32, 0x52, 0x18, 0xEC, 0x35, 0x2F, 0x6C, 0xC9, 0xE6, 0x87, 0xCE, 0x30, 0xF6,
  0xDA, 0x04, 0x3F, 0xA5, 0x8A, 0x0C, 0xAE, 0x5B, 0xB0, 0xEC, 0x29, 0x9B, 0xEE,
  0x8F, 0x52, 0x1E, 0xE2, 0x56, 0x19, 0x45, 0x80, 0x3C, 0x02, 0x57, 0x5C, 0x52,
  0xD9, 0x02, 0x03, 0x01, 0x00, 0x01, 0xA3, 0x82, 0x0C, 0x05, 0x30, 0x82, 0x0C,
  0x01, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04,
  0x03, 0x02, 0x05, 0xA0, 0x30, 0x81, 0x8A, 0x06, 0x08, 0x2B, 0x06, 0x01, 0x05,
  0x05, 0x07, 0x01, 0x01, 0x04, 0x7E, 0x30, 0x7C, 0x30, 0x42, 0x06, 0x08, 0x2B,
  0x06, 0x01, 0x05, 0x05, 0x07, 0x30, 0x02, 0x86, 0x36, 0x68, 0x74, 0x74, 0x70,
  0x3A, 0x2F, 0x2F, 0x73, 0x65, 0x63, 0x75, 0x72, 0x65, 0x2E, 0x67, 0x6C, 0x6F,
  0x62, 0x61, 0x6C, 0x73, 0x69, 0x67, 0x6E, 0x2E, 0x63, 0x6F, 0x6D, 0x2F, 0x63,
  0x61, 0x63, 0x65, 0x72, 0x74, 0x2F, 0x63, 0x6C, 0x6F, 0x75, 0x64, 0x73, 0x73,
  0x6C, 0x73, 0x68, 0x61, 0x32, 0x67, 0x33, 0x2E, 0x63, 0x72, 0x74, 0x30, 0x36,
  0x06, 0x08, 0x2B, 0x06, 0x01, 0x05, 0x05, 0x07, 0x30, 0x01, 0x86, 0x2A, 0x68,
  0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x6F, 0x63, 0x73, 0x70, 0x32, 0x2E, 0x67,
  0x6C, 0x6F, 0x62, 0x61, 0x6C, 0x73, 0x69, 0x67, 0x6E, 0x2E, 0x63, 0x6F, 0x6D,
  0x2F, 0x63, 0x6C, 0x6F, 0x75, 0x64, 0x73, 0x73, 0x6C, 0x73, 0x68, 0x61, 0x32,
  0x67, 0x33, 0x30, 0x56, 0x06, 0x03, 0x55, 0x1D, 0x20, 0x04, 0x4F, 0x30, 0x4D,
  0x30, 0x41, 0x06, 0x09, 0x2B, 0x06, 0x01, 0x04, 0x01, 0xA0, 0x32, 0x01, 0x14,
  0x30, 0x34, 0x30, 0x32, 0x06, 0x08, 0x2B, 0x06, 0x01, 0x05, 0x05, 0x07, 0x02,
  0x01, 0x16, 0x26, 0x68, 0x74, 0x74, 0x70, 0x73, 0x3A, 0x2F, 0x2F, 0x77, 0x77,
  0x77, 0x2E, 0x67, 0x6C, 0x6F, 0x62, 0x61, 0x6C, 0x73, 0x69, 0x67, 0x6E, 0x2E,
  0x63, 0x6F, 0x6D, 0x2F, 0x72, 0x65, 0x70, 0x6F, 0x73, 0x69, 0x74, 0x6F, 0x72,
  0x79, 0x2F, 0x30, 0x08, 0x06, 0x06, 0x67, 0x81, 0x0C, 0x01, 0x02, 0x02, 0x30,
  0x09, 0x06, 0x03, 0x55, 0x1D, 0x13, 0x04, 0x02, 0x30, 0x00, 0x30, 0x82, 0x09,
  0x96, 0x06, 0x03, 0x55, 0x1D, 0x11, 0x04, 0x82, 0x09, 0x8D, 0x30, 0x82, 0x09,
  0x89, 0x82, 0x1B, 0x6A, 0x32, 0x2E, 0x73, 0x68, 0x61, 0x72, 0x65, 0x64, 0x2E,
  0x67, 0x6C, 0x6F, 0x62, 0x61, 0x6C, 0x2E, 0x66, 0x61, 0x73, 0x74, 0x6C, 0x79,
  0x2E, 0x6E, 0x65, 0x74, 0x82, 0x0D, 0x2A, 0x2E, 0x61, 0x32, 0x70, 0x72, 0x65,
  0x73, 0x73, 0x65, 0x2E, 0x66, 0x72, 0x82, 0x19, 0x2A, 0x2E, 0x61, 0x64, 0x76,
  0x65, 0x6E, 0x74, 0x69, 0x73, 0x74, 0x62, 0x6F, 0x6F, 0x6B, 0x63, 0x65, 0x6E,
  0x74, 0x65, 0x72, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x14, 0x2A, 0x2E, 0x61, 0x70,
  0x69, 0x2E, 0x6C, 0x6F, 0x6C, 0x65, 0x73, 0x70, 0x6F, 0x72, 0x74, 0x73, 0x2E,
  0x63, 0x6F, 0x6D, 0x82, 0x0C, 0x2A, 0x2E, 0x62, 0x61, 0x61, 0x74, 0x63, 0x68,
  0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x17, 0x2A, 0x2E, 0x62, 0x69, 0x6F, 0x74, 0x65,
  0x63, 0x68, 0x77, 0x65, 0x65, 0x6B, 0x62, 0x6F, 0x73, 0x74, 0x6F, 0x6E, 0x2E,
  0x63, 0x6F, 0x6D, 0x82, 0x10, 0x2A, 0x2E, 0x62, 0x6F, 0x78, 0x6F, 0x66, 0x73,
  0x74, 0x79, 0x6C, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x0C, 0x2A, 0x2E, 0x63,
  0x61, 0x73, 0x70, 0x65, 0x72, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x11, 0x2A, 0x2E,
  0x63, 0x68, 0x61, 0x6B, 0x72, 0x61, 0x6C, 0x69, 0x6E, 0x75, 0x78, 0x2E, 0x6F,
  0x72, 0x67, 0x82, 0x18, 0x2A, 0x2E, 0x63, 0x6F, 0x6E, 0x76, 0x65, 0x72, 0x74,
  0x2E, 0x64, 0x73, 0x2E, 0x76, 0x65, 0x72, 0x69, 0x7A, 0x6F, 0x6E, 0x2E, 0x63,
  0x6F, 0x6D, 0x82, 0x15, 0x2A, 0x2E, 0x64, 0x65, 0x76, 0x73, 0x70, 0x61, 0x63,
  0x65, 0x73, 0x68, 0x69, 0x70, 0x2E, 0x63, 0x6F, 0x6D, 0x2E, 0x61, 0x75, 0x82,
  0x1B, 0x2A, 0x2E, 0x64, 0x65, 0x76, 0x73, 0x70, 0x61, 0x63, 0x65, 0x73, 0x68,
  0x69, 0x70, 0x69, 0x6E, 0x76, 0x65, 0x73, 0x74, 0x2E, 0x63, 0x6F, 0x6D, 0x2E,
  0x61, 0x75, 0x82, 0x0A, 0x2A, 0x2E, 0x65, 0x63, 0x68, 0x6C, 0x2E, 0x63, 0x6F,
  0x6D, 0x82, 0x0F, 0x2A, 0x2E, 0x66, 0x69, 0x6C, 0x65, 0x73, 0x74, 0x61, 0x63,
  0x6B, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x16, 0x2A, 0x2E, 0x66, 0x69, 0x6C, 0x65,
  0x73, 0x74, 0x61, 0x63, 0x6B, 0x2E, 0x6F, 0x6E, 0x65, 0x6D, 0x6F, 0x62, 0x2E,
  0x63, 0x6F, 0x6D, 0x82, 0x0D, 0x2A, 0x2E, 0x66, 0x69, 0x73, 0x2D, 0x73, 0x6B,
  0x69, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x0C, 0x2A, 0x2E, 0x66, 0x69, 0x73, 0x73,
  0x6B, 0x69, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x14, 0x2A, 0x2E, 0x66, 0x70, 0x2E,
  0x62, 0x72, 0x61, 0x6E, 0x64, 0x66, 0x6F, 0x6C, 0x64, 0x65, 0x72, 0x2E, 0x63,
  0x6F, 0x6D, 0x82, 0x0F, 0x2A, 0x2E, 0x66, 0x73, 0x2E, 0x65, 0x6E, 0x70, 0x6C,
  0x75, 0x67, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x0E, 0x2A, 0x2E, 0x66, 0x73, 0x2E,
  0x65, 0x6E, 0x70, 0x6C, 0x75, 0x67, 0x2E, 0x69, 0x6E, 0x82, 0x10, 0x2A, 0x2E,
  0x66, 0x73, 0x2E, 0x68, 0x65, 0x72, 0x6F, 0x69, 0x6E, 0x65, 0x2E, 0x63, 0x6F,
  0x6D, 0x82, 0x18, 0x2A, 0x2E, 0x66, 0x73, 0x2E, 0x6C, 0x65, 0x61, 0x72, 0x6E,
  0x7A, 0x69, 0x6C, 0x6C, 0x69, 0x6F, 0x6E, 0x63, 0x64, 0x6E, 0x2E, 0x63, 0x6F,
  0x6D, 0x82, 0x18, 0x2A, 0x2E, 0x66, 0x73, 0x2E, 0x6C, 0x6F, 0x63, 0x61, 0x6C,
  0x7A, 0x69, 0x6C, 0x6C, 0x69, 0x6F, 0x6E, 0x63, 0x64, 0x6E, 0x2E, 0x63, 0x6F,
  0x6D, 0x82, 0x12, 0x2A, 0x2E, 0x66, 0x73, 0x2E, 0x6D, 0x69, 0x6E, 0x64, 0x66,
  0x6C, 0x61, 0x73, 0x68, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x16, 0x2A, 0x2E, 0x66,
  0x73, 0x2E, 0x6F, 0x70, 0x73, 0x7A, 0x69, 0x6C, 0x6C, 0x69, 0x6F, 0x6E, 0x63,
  0x64, 0x6E, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x10, 0x2A, 0x2E, 0x66, 0x73, 0x2E,
  0x70, 0x69, 0x78, 0x76, 0x61, 0x6E, 0x61, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x15,
  0x2A, 0x2E, 0x66, 0x73, 0x2E, 0x71, 0x61, 0x7A, 0x69, 0x6C, 0x6C, 0x69, 0x6F,
  0x6E, 0x63, 0x64, 0x6E, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x17, 0x2A, 0x2E, 0x66,
  0x73, 0x2E, 0x74, 0x65, 0x73, 0x74, 0x7A, 0x69, 0x6C, 0x6C, 0x69, 0x6F, 0x6E,
  0x63, 0x64, 0x6E, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x09, 0x2A, 0x2E, 0x68, 0x61,
  0x78, 0x78, 0x2E, 0x73, 0x65, 0x82, 0x0D, 0x2A, 0x2E, 0x68, 0x6F, 0x6D, 0x65,
  0x61, 0x77, 0x61, 0x79, 0x2E, 0x6C, 0x6B, 0x82, 0x0F, 0x2A, 0x2E, 0x69, 0x64,
  0x61, 0x74, 0x61, 0x6C, 0x69, 0x6E, 0x6B, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x16,
  0x2A, 0x2E, 0x69, 0x64, 0x61, 0x74, 0x61, 0x6C, 0x69, 0x6E, 0x6B, 0x6D, 0x61,
  0x65, 0x73, 0x74, 0x72, 0x6F, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x11, 0x2A, 0x2E,
  0x69, 0x6D, 0x67, 0x2D, 0x74, 0x61, 0x62, 0x6F, 0x6F, 0x6C, 0x61, 0x2E, 0x63,
  0x6F, 0x6D, 0x82, 0x0F, 0x2A, 0x2E, 0x6A, 0x75, 0x6C, 0x69, 0x61, 0x6C, 0x61,
  0x6E, 0x67, 0x2E, 0x6F, 0x72, 0x67, 0x82, 0x10, 0x2A, 0x2E, 0x6B, 0x69, 0x6E,
  0x64, 0x73, 0x6E, 0x61, 0x63, 0x6B, 0x73, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x10,
  0x2A, 0x2E, 0x6B, 0x73, 0x73, 0x76, 0x61, 0x6E, 0x69, 0x6C, 0x6C, 0x61, 0x2E,
  0x63, 0x6F, 0x6D, 0x82, 0x0E, 0x2A, 0x2E, 0x6B, 0x73, 0x74, 0x63, 0x6F, 0x72,
  0x72, 0x61, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x10, 0x2A, 0x2E, 0x6B, 0x73, 0x74,
  0x76, 0x61, 0x6E, 0x69, 0x6C, 0x6C, 0x61, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x0C,
  0x2A, 0x2E, 0x6E, 0x65, 0x77, 0x73, 0x31, 0x32, 0x2E, 0x63, 0x6F, 0x6D, 0x82,
  0x1B, 0x2A, 0x2E, 0x70, 0x61, 0x72, 0x74, 0x69, 0x64, 0x65, 0x6E, 0x74, 0x69,
  0x66, 0x69, 0x65, 0x72, 0x2E, 0x73, 0x77, 0x69, 0x73, 0x63, 0x6F, 0x2E, 0x63,
  0x6F, 0x6D, 0x82, 0x13, 0x2A, 0x2E, 0x73, 0x68, 0x6F, 0x70, 0x72, 0x61, 0x63,
  0x68, 0x65, 0x6C, 0x7A, 0x6F, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x0A, 0x2A,
  0x2E, 0x74, 0x61, 0x73, 0x74, 0x79, 0x2E, 0x63, 0x6F, 0x82, 0x0C, 0x2A, 0x2E,
  0x74, 0x65, 0x64, 0x63, 0x64, 0x6E, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x15, 0x2A,
  0x2E, 0x75, 0x70, 0x6C, 0x6F, 0x61, 0x64, 0x73, 0x2E, 0x66, 0x6F, 0x6C, 0x69,
  0x6F, 0x68, 0x64, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x14, 0x2A, 0x2E, 0x76, 0x6F,
  0x75, 0x63, 0x68, 0x65, 0x72, 0x63, 0x6F, 0x64, 0x65, 0x73, 0x2E, 0x63, 0x6F,
  0x2E, 0x75, 0x6B, 0x82, 0x0D, 0x2A, 0x2E, 0x77, 0x65, 0x61, 0x74, 0x68, 0x65,
  0x72, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x0D, 0x61, 0x2E, 0x69, 0x63, 0x61, 0x6E,
  0x76, 0x61, 0x73, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x0B, 0x61, 0x32, 0x70, 0x72,
  0x65, 0x73, 0x73, 0x65, 0x2E, 0x66, 0x72, 0x82, 0x17, 0x61, 0x64, 0x76, 0x65,
  0x6E, 0x74, 0x69, 0x73, 0x74, 0x62, 0x6F, 0x6F, 0x6B, 0x63, 0x65, 0x6E, 0x74,
  0x65, 0x72, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x11, 0x61, 0x70, 0x69, 0x2D, 0x6D,
  0x65, 0x72, 0x72, 0x79, 0x6A, 0x61, 0x6E, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x82,
  0x12, 0x61, 0x70, 0x69, 0x73, 0x2E, 0x69, 0x64, 0x61, 0x74, 0x61, 0x6C, 0x69,
  0x76, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x0F, 0x61, 0x70, 0x70, 0x2D, 0x61,
  0x70, 0x69, 0x2E, 0x74, 0x65, 0x64, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x12, 0x61,
  0x70, 0x70, 0x2E, 0x62, 0x69, 0x72, 0x63, 0x68, 0x62, 0x6F, 0x78, 0x2E, 0x63,
  0x6F, 0x2E, 0x75, 0x6B, 0x82, 0x0F, 0x61, 0x70, 0x70, 0x2E, 0x62, 0x69, 0x72,
  0x63, 0x68, 0x62, 0x6F, 0x78, 0x2E, 0x65, 0x73, 0x82, 0x1A, 0x61, 0x70, 0x70,
  0x2E, 0x73, 0x74, 0x61, 0x67, 0x69, 0x6E, 0x67, 0x2E, 0x62, 0x69, 0x72, 0x63,
  0x68, 0x62, 0x6F, 0x78, 0x2E, 0x63, 0x6F, 0x2E, 0x75, 0x6B, 0x82, 0x17, 0x61,
  0x70, 0x70, 0x2E, 0x73, 0x74, 0x61, 0x67, 0x69, 0x6E, 0x67, 0x2E, 0x62, 0x69,
  0x72, 0x63, 0x68, 0x62, 0x6F, 0x78, 0x2E, 0x65, 0x73, 0x82, 0x0A, 0x62, 0x61,
  0x61, 0x74, 0x63, 0x68, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x13, 0x62, 0x65, 0x72,
  0x6E, 0x61, 0x72, 0x64, 0x63, 0x6F, 0x6E, 0x74, 0x72, 0x6F, 0x6C, 0x73, 0x2E,
  0x63, 0x6F, 0x6D, 0x82, 0x15, 0x62, 0x69, 0x6F, 0x74, 0x65, 0x63, 0x68, 0x77,
  0x65, 0x65, 0x6B, 0x62, 0x6F, 0x73, 0x74, 0x6F, 0x6E, 0x2E, 0x63, 0x6F, 0x6D,
  0x82, 0x0E, 0x62, 0x6F, 0x78, 0x6F, 0x66, 0x73, 0x74, 0x79, 0x6C, 0x65, 0x2E,
  0x63, 0x6F, 0x6D, 0x82, 0x0A, 0x63, 0x61, 0x73, 0x70, 0x65, 0x72, 0x2E, 0x63,
  0x6F, 0x6D, 0x82, 0x0D, 0x63, 0x64, 0x6E, 0x2E, 0x69, 0x72, 0x73, 0x64, 0x6E,
  0x2E, 0x6E, 0x65, 0x74, 0x82, 0x0F, 0x63, 0x68, 0x61, 0x6B, 0x72, 0x61, 0x6C,
  0x69, 0x6E, 0x75, 0x78, 0x2E, 0x6F, 0x72, 0x67, 0x82, 0x13, 0x64, 0x65, 0x76,
  0x73, 0x70, 0x61, 0x63, 0x65, 0x73, 0x68, 0x69, 0x70, 0x2E, 0x63, 0x6F, 0x6D,
  0x2E, 0x61, 0x75, 0x82, 0x0B, 0x64, 0x69, 0x67, 0x69, 0x64, 0x61, 0x79, 0x2E,
  0x63, 0x6F, 0x6D, 0x82, 0x22, 0x64, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6C, 0x4C,
  0x69, 0x62, 0x72, 0x61, 0x72, 0x79, 0x2E, 0x62, 0x65, 0x72, 0x6E, 0x61, 0x72,
  0x64, 0x63, 0x6F, 0x6E, 0x74, 0x72, 0x6F, 0x6C, 0x73, 0x2E, 0x63, 0x6F, 0x6D,
  0x82, 0x14, 0x64, 0x72, 0x77, 0x70, 0x2E, 0x73, 0x74, 0x61, 0x67, 0x69, 0x6E,
  0x67, 0x2E, 0x6D, 0x6F, 0x6F, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x08, 0x65, 0x63,
  0x68, 0x6C, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x14, 0x66, 0x69, 0x6C, 0x65, 0x73,
  0x74, 0x61, 0x63, 0x6B, 0x2E, 0x6F, 0x6E, 0x65, 0x6D, 0x6F, 0x62, 0x2E, 0x63,
  0x6F, 0x6D, 0x82, 0x0D, 0x66, 0x73, 0x2E, 0x65, 0x6E, 0x70, 0x6C, 0x75, 0x67,
  0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x16, 0x66, 0x73, 0x2E, 0x6C, 0x65, 0x61, 0x72,
  0x6E, 0x7A, 0x69, 0x6C, 0x6C, 0x69, 0x6F, 0x6E, 0x63, 0x64, 0x6E, 0x2E, 0x63,
  0x6F, 0x6D, 0x82, 0x16, 0x66, 0x73, 0x2E, 0x6C, 0x6F, 0x63, 0x61, 0x6C, 0x7A,
  0x69, 0x6C, 0x6C, 0x69, 0x6F, 0x6E, 0x63, 0x64, 0x6E, 0x2E, 0x63, 0x6F, 0x6D,
  0x82, 0x14, 0x66, 0x73, 0x2E, 0x6F, 0x70, 0x73, 0x7A, 0x69, 0x6C, 0x6C, 0x69,
  0x6F, 0x6E, 0x63, 0x64, 0x6E, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x13, 0x66, 0x73,
  0x2E, 0x71, 0x61, 0x7A, 0x69, 0x6C, 0x6C, 0x69, 0x6F, 0x6E, 0x63, 0x64, 0x6E,
  0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x15, 0x66, 0x73, 0x2E, 0x74, 0x65, 0x73, 0x74,
  0x7A, 0x69, 0x6C, 0x6C, 0x69, 0x6F, 0x6E, 0x63, 0x64, 0x6E, 0x2E, 0x63, 0x6F,
  0x6D, 0x82, 0x0B, 0x68, 0x6F, 0x6D, 0x65, 0x61, 0x77, 0x61, 0x79, 0x2E, 0x6C,
  0x6B, 0x82, 0x12, 0x69, 0x6D, 0x67, 0x2E, 0x74, 0x72, 0x69, 0x67, 0x67, 0x65,
  0x72, 0x6D, 0x61, 0x69, 0x6C, 0x2E, 0x69, 0x6F, 0x82, 0x0E, 0x6B, 0x69, 0x6E,
  0x64, 0x73, 0x6E, 0x61, 0x63, 0x6B, 0x73, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x0E,
  0x6B, 0x73, 0x73, 0x76, 0x61, 0x6E, 0x69, 0x6C, 0x6C, 0x61, 0x2E, 0x63, 0x6F,
  0x6D, 0x82, 0x0C, 0x6B, 0x73, 0x74, 0x63, 0x6F, 0x72, 0x72, 0x61, 0x2E, 0x63,
  0x6F, 0x6D, 0x82, 0x0D, 0x6D, 0x65, 0x6E, 0x75, 0x2E, 0x74, 0x72, 0x65, 0x65,
  0x7A, 0x2E, 0x69, 0x6F, 0x82, 0x17, 0x6D, 0x6F, 0x62, 0x69, 0x6C, 0x65, 0x61,
  0x70, 0x69, 0x2E, 0x69, 0x64, 0x61, 0x74, 0x61, 0x6C, 0x69, 0x6E, 0x6B, 0x2E,
  0x63, 0x6F, 0x6D, 0x82, 0x0A, 0x6E, 0x65, 0x77, 0x73, 0x31, 0x32, 0x2E, 0x63,
  0x6F, 0x6D, 0x82, 0x0B, 0x6F, 0x6D, 0x6E, 0x69, 0x67, 0x6F, 0x6E, 0x2E, 0x63,
  0x6F, 0x6D, 0x82, 0x0E, 0x6F, 0x72, 0x65, 0x69, 0x6C, 0x6C, 0x79, 0x2E, 0x72,
  0x65, 0x76, 0x69, 0x65, 0x77, 0x82, 0x11, 0x70, 0x6F, 0x70, 0x79, 0x6F, 0x75,
  0x72, 0x62, 0x75, 0x62, 0x62, 0x6C, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x18,
  0x70, 0x72, 0x6F, 0x64, 0x2E, 0x62, 0x65, 0x72, 0x6E, 0x61, 0x72, 0x64, 0x63,
  0x6F, 0x6E, 0x74, 0x72, 0x6F, 0x6C, 0x73, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x18,
  0x72, 0x65, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x2D, 0x70, 0x72, 0x69, 0x6D, 0x65,
  0x2E, 0x73, 0x70, 0x6F, 0x6B, 0x65, 0x6F, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x19,
  0x72, 0x65, 0x70, 0x6F, 0x73, 0x69, 0x74, 0x6F, 0x72, 0x69, 0x65, 0x73, 0x2E,
  0x73, 0x65, 0x6E, 0x73, 0x75, 0x61, 0x70, 0x70, 0x2E, 0x6F, 0x72, 0x67, 0x82,
  0x0C, 0x72, 0x6C, 0x2E, 0x74, 0x61, 0x6C, 0x69, 0x73, 0x2E, 0x63, 0x6F, 0x6D,
  0x82, 0x11, 0x73, 0x68, 0x6F, 0x70, 0x72, 0x61, 0x63, 0x68, 0x65, 0x6C, 0x7A,
  0x6F, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x0F, 0x73, 0x74, 0x61, 0x67, 0x69,
  0x6E, 0x67, 0x2E, 0x6D, 0x6F, 0x6F, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x14, 0x73,
  0x74, 0x61, 0x74, 0x69, 0x63, 0x2E, 0x70, 0x6C, 0x75, 0x6D, 0x63, 0x61, 0x63,
  0x68, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x14, 0x73, 0x74, 0x61, 0x79, 0x69,
  0x6E, 0x67, 0x61, 0x6C, 0x69, 0x76, 0x65, 0x2E, 0x6D, 0x73, 0x66, 0x2E, 0x6F,
  0x72, 0x67, 0x82, 0x08, 0x74, 0x61, 0x73, 0x74, 0x79, 0x2E, 0x63, 0x6F, 0x82,
  0x0C, 0x74, 0x6F, 0x70, 0x73, 0x70, 0x65, 0x65, 0x64, 0x2E, 0x63, 0x6F, 0x6D,
  0x82, 0x13, 0x75, 0x70, 0x6C, 0x6F, 0x61, 0x64, 0x73, 0x2E, 0x66, 0x6F, 0x6C,
  0x69, 0x6F, 0x68, 0x64, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x1A, 0x75, 0x73, 0x2D,
  0x65, 0x75, 0x2E, 0x66, 0x69, 0x6C, 0x65, 0x73, 0x74, 0x61, 0x63, 0x6B, 0x63,
  0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x12, 0x76,
  0x6F, 0x75, 0x63, 0x68, 0x65, 0x72, 0x63, 0x6F, 0x64, 0x65, 0x73, 0x2E, 0x63,
  0x6F, 0x2E, 0x75, 0x6B, 0x82, 0x0B, 0x77, 0x65, 0x61, 0x74, 0x68, 0x65, 0x72,
  0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x13, 0x77, 0x6F, 0x6D, 0x65, 0x6E, 0x73, 0x68,
  0x65, 0x61, 0x6C, 0x74, 0x68, 0x2D, 0x6A, 0x70, 0x2E, 0x63, 0x6F, 0x6D, 0x82,
  0x19, 0x77, 0x6F, 0x72, 0x6B, 0x65, 0x72, 0x62, 0x65, 0x65, 0x2E, 0x73, 0x74,
  0x61, 0x67, 0x69, 0x6E, 0x67, 0x2E, 0x6D, 0x6F, 0x6F, 0x2E, 0x63, 0x6F, 0x6D,
  0x82, 0x0A, 0x77, 0x77, 0x77, 0x2E, 0x61, 0x67, 0x66, 0x2E, 0x64, 0x6B, 0x82,
  0x14, 0x77, 0x77, 0x77, 0x2E, 0x61, 0x76, 0x65, 0x6E, 0x69, 0x72, 0x2D, 0x73,
  0x75, 0x69, 0x73, 0x73, 0x65, 0x2E, 0x63, 0x68, 0x82, 0x11, 0x77, 0x77, 0x77,
  0x2E, 0x63, 0x61, 0x6E, 0x73, 0x74, 0x61, 0x72, 0x2E, 0x63, 0x6F, 0x2E, 0x6E,
  0x7A, 0x82, 0x15, 0x77, 0x77, 0x77, 0x2E, 0x63, 0x61, 0x6E, 0x73, 0x74, 0x61,
  0x72, 0x62, 0x6C, 0x75, 0x65, 0x2E, 0x63, 0x6F, 0x2E, 0x6E, 0x7A, 0x82, 0x16,
  0x77, 0x77, 0x77, 0x2E, 0x63, 0x61, 0x6E, 0x73, 0x74, 0x61, 0x72, 0x62, 0x6C,
  0x75, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x2E, 0x61, 0x75, 0x82, 0x1D, 0x77, 0x77,
  0x77, 0x2E, 0x63, 0x68, 0x61, 0x6D, 0x70, 0x69, 0x6F, 0x6E, 0x73, 0x68, 0x6F,
  0x63, 0x6B, 0x65, 0x79, 0x6C, 0x65, 0x61, 0x67, 0x75, 0x65, 0x2E, 0x6E, 0x65,
  0x74, 0x82, 0x0F, 0x77, 0x77, 0x77, 0x2E, 0x65, 0x78, 0x74, 0x65, 0x72, 0x72,
  0x6F, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x0C, 0x77, 0x77, 0x77, 0x2E, 0x65, 0x7A,
  0x75, 0x70, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x0B, 0x77, 0x77, 0x77, 0x2E, 0x65,
  0x7A, 0x75, 0x70, 0x2E, 0x64, 0x65, 0x82, 0x0B, 0x77, 0x77, 0x77, 0x2E, 0x65,
  0x7A, 0x75, 0x70, 0x2E, 0x65, 0x75, 0x82, 0x0B, 0x77, 0x77, 0x77, 0x2E, 0x65,
  0x7A, 0x75, 0x70, 0x2E, 0x6E, 0x6C, 0x82, 0x11, 0x77, 0x77, 0x77, 0x2E, 0x66,
  0x72, 0x61, 0x6E, 0x6B, 0x62, 0x6F, 0x64, 0x79, 0x2E, 0x63, 0x6F, 0x6D, 0x82,
  0x0D, 0x77, 0x77, 0x77, 0x2E, 0x67, 0x6C, 0x6F, 0x73, 0x73, 0x79, 0x2E, 0x63,
  0x6F, 0x82, 0x0F, 0x77, 0x77, 0x77, 0x2E, 0x67, 0x6F, 0x6C, 0x64, 0x63, 0x75,
  0x70, 0x2E, 0x6F, 0x72, 0x67, 0x82, 0x0F, 0x77, 0x77, 0x77, 0x2E, 0x69, 0x63,
  0x61, 0x6E, 0x76, 0x61, 0x73, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x0D, 0x77, 0x77,
  0x77, 0x2E, 0x6D, 0x6F, 0x6E, 0x69, 0x6E, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x16,
  0x77, 0x77, 0x77, 0x2E, 0x6F, 0x64, 0x65, 0x6E, 0x73, 0x65, 0x2D, 0x6D, 0x61,
  0x72, 0x63, 0x69, 0x70, 0x61, 0x6E, 0x2E, 0x64, 0x6B, 0x82, 0x15, 0x77, 0x77,
  0x77, 0x2E, 0x6F, 0x6E, 0x65, 0x63, 0x6C, 0x69, 0x63, 0x6B, 0x64, 0x72, 0x69,
  0x76, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x12, 0x77, 0x77, 0x77, 0x2E, 0x6F,
  0x72, 0x65, 0x69, 0x6C, 0x6C, 0x79, 0x2E, 0x72, 0x65, 0x76, 0x69, 0x65, 0x77,
  0x82, 0x15, 0x77, 0x77, 0x77, 0x2E, 0x70, 0x6F, 0x70, 0x79, 0x6F, 0x75, 0x72,
  0x62, 0x75, 0x62, 0x62, 0x6C, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x82, 0x0E, 0x77,
  0x77, 0x77, 0x2E, 0x72, 0x61, 0x77, 0x6E, 0x65, 0x74, 0x2E, 0x63, 0x6F, 0x6D,
  0x82, 0x0E, 0x77, 0x77, 0x77, 0x2E, 0x73, 0x70, 0x6F, 0x6B, 0x65, 0x6F, 0x2E,
  0x63, 0x6F, 0x6D, 0x82, 0x10, 0x77, 0x77, 0x77, 0x2E, 0x74, 0x65, 0x61, 0x72,
  0x73, 0x68, 0x65, 0x65, 0x74, 0x2E, 0x63, 0x6F, 0x82, 0x10, 0x77, 0x77, 0x77,
  0x2E, 0x74, 0x6F, 0x70, 0x73, 0x70, 0x65, 0x65, 0x64, 0x2E, 0x63, 0x6F, 0x6D,
  0x82, 0x16, 0x77, 0x77, 0x77, 0x2E, 0x77, 0x68, 0x69, 0x74, 0x65, 0x6B, 0x65,
  0x79, 0x76, 0x69, 0x6C, 0x6C, 0x61, 0x73, 0x2E, 0x63, 0x6F, 0x6D, 0x30, 0x1D,
  0x06, 0x03, 0x55, 0x1D, 0x25, 0x04, 0x16, 0x30, 0x14, 0x06, 0x08, 0x2B, 0x06,
  0x01, 0x05, 0x05, 0x07, 0x03, 0x01, 0x06, 0x08, 0x2B, 0x06, 0x01, 0x05, 0x05,
  0x07, 0x03, 0x02, 0x30, 0x1D, 0x06, 0x03, 0x55, 0x1D, 0x0E, 0x04, 0x16, 0x04,
  0x14, 0xA8, 0x29, 0xFD, 0xA9, 0xA5, 0x1A, 0x1C, 0x37, 0x0B, 0x20, 0x3B, 0x98,
  0xB7, 0x25, 0x39, 0xCC, 0xE5, 0x2F, 0xF4, 0x94, 0x30, 0x1F, 0x06, 0x03, 0x55,
  0x1D, 0x23, 0x04, 0x18, 0x30, 0x16, 0x80, 0x14, 0xA9, 0x2B, 0x87, 0xE1, 0xCE,
  0x24, 0x47, 0x3B, 0x1B, 0xBF, 0xCF, 0x85, 0x37, 0x02, 0x55, 0x9D, 0x0D, 0x94,
  0x58, 0xE6, 0x30, 0x82, 0x01, 0x04, 0x06, 0x0A, 0x2B, 0x06, 0x01, 0x04, 0x01,
  0xD6, 0x79, 0x02, 0x04, 0x02, 0x04, 0x81, 0xF5, 0x04, 0x81, 0xF2, 0x00, 0xF0,
  0x00, 0x77, 0x00, 0xA4, 0xB9, 0x09, 0x90, 0xB4, 0x18, 0x58, 0x14, 0x87, 0xBB,
  0x13, 0xA2, 0xCC, 0x67, 0x70, 0x0A, 0x3C, 0x35, 0x98, 0x04, 0xF9, 0x1B, 0xDF,
  0xB8, 0xE3, 0x77, 0xCD, 0x0E, 0xC8, 0x0D, 0xDC, 0x10, 0x00, 0x00, 0x01, 0x66,
  0x9C, 0xC8, 0xE7, 0x38, 0x00, 0x00, 0x04, 0x03, 0x00, 0x48, 0x30, 0x46, 0x02,
  0x21, 0x00, 0xD9, 0x58, 0x6E, 0xFC, 0x4C, 0x3C, 0xAF, 0xF9, 0x5B, 0x7F, 0xDA,
  0x54, 0x95, 0xAF, 0xCF, 0xB3, 0x57, 0xB9, 0x56, 0x2C, 0xE8, 0xE0, 0xB1, 0x20,
  0x9B, 0xCB, 0x75, 0xAC, 0x4E, 0x54, 0xE9, 0x9D, 0x02, 0x21, 0x00, 0xE8, 0xF0,
  0xC0, 0x49, 0x23, 0x8E, 0x3D, 0x9B, 0xA5, 0x87, 0xA3, 0xBE, 0x6C, 0x21, 0x62,
  0xBB, 0xD2, 0x44, 0x5C, 0xE4, 0x7A, 0xCC, 0x46, 0x26, 0x04, 0x19, 0xA4, 0x2D,
  0x9B, 0x1C, 0x5D, 0x3A, 0x00, 0x75, 0x00, 0x6F, 0x53, 0x76, 0xAC, 0x31, 0xF0,
  0x31, 0x19, 0xD8, 0x99, 0x00, 0xA4, 0x51, 0x15, 0xFF, 0x77, 0x15, 0x1C, 0x11,
  0xD9, 0x02, 0xC1, 0x00, 0x29, 0x06, 0x8D, 0xB2, 0x08, 0x9A, 0x37, 0xD9, 0x13,
  0x00, 0x00, 0x01, 0x66, 0x9C, 0xC8, 0xE6, 0x20, 0x00, 0x00, 0x04, 0x03, 0x00,
  0x46, 0x30, 0x44, 0x02, 0x20, 0x14, 0xC8, 0x9F, 0xAC, 0x27, 0x48, 0xBE, 0x4D,
  0x0E, 0xC3, 0x26, 0x2E, 0x34, 0xCA, 0x38, 0xBA, 0x11, 0x3A, 0x68, 0x71, 0x88,
  0xEB, 0x24, 0x26, 0x59, 0x3E, 0xAC, 0xA8, 0x63, 0xCC, 0x8A, 0x0A, 0x02, 0x20,
  0x0F, 0x22, 0xBF, 0x0D, 0x1F, 0x8A, 0x8D, 0x1D, 0x91, 0x33, 0x3A, 0x40, 0xE4,
  0x23, 0x78, 0xFA, 0x22, 0xF5, 0x9B, 0xCB, 0x04, 0x4F, 0x53, 0x2D, 0x20, 0x75,
  0x2F, 0x76, 0x8A, 0xB1, 0xCD, 0x9D, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48,
  0x86, 0xF7, 0x0D, 0x01, 0x01, 0x0B, 0x05, 0x00, 0x03, 0x82, 0x01, 0x01, 0x00,
  0x03, 0x41, 0x0F, 0xF3, 0xA6, 0x62, 0xA2, 0xE5, 0xB4, 0x8D, 0xA8, 0x08, 0x71,
  0x7B, 0xB3, 0xE3, 0x51, 0x61, 0x0D, 0xC0, 0x67, 0x6C, 0x3C, 0x9C, 0x00, 0x0B,
  0x63, 0x77, 0xB6, 0xB6, 0x11, 0x67, 0x77, 0xA5, 0xE1, 0x49, 0xE0, 0x7F, 0xB7,
  0x1D, 0x61, 0xFB, 0x83, 0x9C, 0x83, 0x42, 0xE9, 0x31, 0xCA, 0x51, 0xE3, 0xC1,
  0xBD, 0x9B, 0x2F, 0xB5, 0x35, 0x05, 0x72, 0x7F, 0x40, 0xA6, 0x7C, 0xC9, 0xF1,
  0x59, 0xA7, 0x15, 0xB8, 0x12, 0xDA, 0xF8, 0xCE, 0x83, 0x61, 0xFC, 0x47, 0x96,
  0x9E, 0x74, 0xFE, 0xCD, 0xE4, 0x61, 0x92, 0xF2, 0x2E, 0x0C, 0x08, 0x4B, 0x60,
  0x2D, 0xF6, 0x50, 0x07, 0x83, 0xCA, 0xAF, 0xB9, 0x41, 0x33, 0x4A, 0x3E, 0x84,
  0xC7, 0x73, 0xC6, 0x1F, 0xFF, 0x7A, 0xDF, 0xAE, 0x47, 0x25, 0x32, 0xEB, 0xC0,
  0x43, 0x0C, 0xA6, 0x23, 0x13, 0x46, 0xC3, 0xFA, 0x44, 0xEA, 0x20, 0xEA, 0xCB,
  0x18, 0x17, 0x00, 0xB6, 0xE7, 0x6D, 0x8A, 0x14, 0x8C, 0x6A, 0xCA, 0x88, 0x4C,
  0xDA, 0xA8, 0xB9, 0x08, 0xAF, 0x39, 0xEE, 0xCF, 0xD7, 0xF7, 0x32, 0xC0, 0xF4,
  0xCF, 0x4E, 0x22, 0x38, 0xF7, 0xAF, 0xAE, 0x7D, 0x58, 0x5F, 0xA5, 0x2D, 0x4D,
  0xBB, 0x86, 0x10, 0xB3, 0x93, 0x62, 0x64, 0x27, 0xBF, 0xB1, 0xBB, 0x8F, 0x9F,
  0xFC, 0x07, 0x3C, 0x4B, 0x16, 0x7A, 0x84, 0x5E, 0xAF, 0xAD, 0x57, 0x9C, 0xFF,
  0x7A, 0xA7, 0xE0, 0x90, 0x89, 0x1C, 0xE8, 0xE5, 0x11, 0xF7, 0xB6, 0xDC, 0xCD,
  0x5E, 0xF7, 0x30, 0xA2, 0x2E, 0x67, 0x6D, 0x4A, 0x70, 0x26, 0xEA, 0xCD, 0x27,
  0x70, 0x77, 0x54, 0x57, 0x09, 0x03, 0x56, 0x4A, 0x33, 0x60, 0x00, 0x27, 0xFE,
  0xA7, 0xD7, 0xA9, 0xC4, 0xEC, 0x17, 0x17, 0x8D, 0x87, 0x70, 0x6B, 0x48, 0x88,
  0x61, 0x54, 0x4A, 0x2B, 0xB7, 0x6A, 0x12, 0x08, 0xFB,
};

UNITTEST_START
{
  CURLcode result;
  struct connectdata conn;
  const char *beg = (const char *)&cert[0];
  const char *end = (const char *)&cert[sizeof(cert)];
  struct Curl_easy *data = curl_easy_init();
  int i;
  int byte;
  if(!data)
    return 2;

  memset(&conn, 0, sizeof(struct connectdata));
  /* this is a lot of assuming, but we expect the parsing function to only
     really need the easy handle pointer */
  conn.data = data;
  result = Curl_extract_certinfo(&conn, 0, beg, end);

  fail_unless(result == CURLE_OK, "Curl_extract_certinfo returned error");

  /* a poor man's fuzzing of some initial data to make sure nothing bad
     happens */
  for(byte = 1 ; byte < 255; byte += 17) {
    for(i = 0; i < 45; i++) {
      char backup = cert[i];
      cert[i] = (unsigned char)byte&0xff;
      (void) Curl_extract_certinfo(&conn, 0, beg, end);
      cert[i] = backup;
    }
  }
  curl_easy_cleanup(data);
}
UNITTEST_STOP

#else

UNITTEST_START
{
  puts("not tested since Curl_extract_certinfo() is not built-in");
}
UNITTEST_STOP

#endif
