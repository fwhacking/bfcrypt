/*
 * Copyright (C) 2011 <fwhacking|gmail:com>
 *
 * This is free software, licensed under the GNU General Public License v2.
 * See /LICENSE for more information.
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "bfcrypt.h"
#include "crc32.h"

int find_crc32(char *base, size_t offset)
{
	int found;
	
	found = find_crc32_poly(base + offset);
	
	if (found >= 0)
	{
		printf("%s (0x%08x) found at 0x%08lx\n", CRC32_TABLE[0].desc, CRC32_TABLE[0].poly, (unsigned long) offset);
	}
	
	return 0;
}

int find_crc32_poly(char *p)
{
	int ret = -1;
	unsigned int i;
	
	for (i = 0; i < sizeof(CRC32_TABLE) / sizeof(CRC32_TABLE[0]); i++)
	{
		if (memcmp(&CRC32_TABLE[i].poly, p, sizeof(CRC32_TABLE[0].poly)) == 0)
		{
			ret = i;
			break;
		}
	}
	
	return ret;
}
