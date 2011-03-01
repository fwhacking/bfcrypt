/*
 * Copyright (C) 2011 <fwhacking|gmail:com>
 *
 * This is free software, licensed under the GNU General Public License v2.
 * See /LICENSE for more information.
 *
 */

#ifndef _CRC32_H_
#define _CRC32_H_

/*
 * http://en.wikipedia.org/wiki/Cyclic_redundancy_check
 */

int find_crc32(char *base, size_t offset);
int find_crc32_poly(char *p);

typedef struct _crc32 {
	char *desc;
	uint32_t poly;
} crc32;

static crc32 CRC32_TABLE[8] =
{
	{ "CRC-32-IEEE 802.3", 0x04c11db7L},
	{ "CRC-32-IEEE 802.3 (reversed)", 0xedb88320L},
	{ "CRC-32C (Castagnoli)", 0x1edc6f41L},
	{ "CRC-32C (Castagnoli) (reversed)", 0x82f63b78L},
	{ "CRC-32K (Koopman)", 0x741b8cd7L},
	{ "CRC-32K (Koopman) (reversed)", 0xeb31d82eL},
	{ "CRC-32Q", 0x814141abL},
	{ "CRC-32Q (reversed)", 0xd5828281L}
};

#endif // _CRC32_H_
