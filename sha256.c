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
#include "sha256.h"

int find_sha256(char *base, size_t offset)
{
	if (find_sha256_init(base + offset) == 0)
	{
		printf("SHA256 Init      (0x%08x) found at 0x%08lx\n", SHA256_INIT[0], (unsigned long) offset);
	}

	if (find_sha256_constants(base + offset) == 0)
	{
		printf("SHA256 Constants (0x%08x) found at 0x%08lx\n", SHA256_CONSTANTS[0], (unsigned long) offset);
	}
	
	return 0;
}

int find_sha256_init(char *p)
{
	int ret = -1;
	unsigned int i;
	
	if (memcmp(SHA256_INIT, p, sizeof(SHA256_INIT[0])) == 0)
	{
		ret = 0;
		
		for (i = 0; i < sizeof(SHA256_INIT) / sizeof(SHA256_INIT[0]); i++)
		{
			if (memcmp(&SHA256_INIT[i], p + i * sizeof(SHA256_INIT[0]), sizeof(SHA256_INIT[0])) != 0)
			{
				ret = -1;
			}
		}
	}
	
	return ret;
}

int find_sha256_constants(char *p)
{
	int ret = -1;
	unsigned int i;
	
	if (memcmp(SHA256_CONSTANTS, p, sizeof(SHA256_CONSTANTS[0])) == 0)
	{
		ret = 0;
		
		for (i = 0; i < sizeof(SHA256_CONSTANTS) / sizeof(SHA256_CONSTANTS[0]); i++)
		{
			if (memcmp(&SHA256_CONSTANTS[i], p + i * sizeof(SHA256_CONSTANTS[0]), sizeof(SHA256_CONSTANTS[0])) != 0)
			{
				ret = -1;
			}
		}
	}
	
	return ret;
}
