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
#include "md5.h"

int find_md5(char *base, size_t offset)
{
	if (find_md5_digest(base + offset) == 0)
	{
		printf("MD Digest   (0x%08x) found at 0x%08lx\n", MD5_DIGEST[0], (unsigned long) offset);
	}

	if (find_md5_constants(base + offset) == 0)
	{
		printf("MD5 Constants (0x%08x) found at 0x%08lx\n", MD5_CONSTANTS[0], (unsigned long) offset);
	}
	
	return 0;
}

int find_md5_digest(char *p)
{
	int ret = -1;
	unsigned int i;
	
	if (memcmp(MD5_DIGEST, p, sizeof(MD5_DIGEST[0])) == 0)
	{
		ret = 0;
		
		for (i = 0; i < sizeof(MD5_DIGEST) / sizeof(MD5_DIGEST[0]); i++)
		{
			if (memcmp(&MD5_DIGEST[i], p + i * sizeof(MD5_DIGEST[0]), sizeof(MD5_DIGEST[0])) != 0)
			{
				ret = -1;
			}
		}
	}
	
	return ret;
}

int find_md5_constants(char *p)
{
	int ret = -1;
	unsigned int i;
	
	if (memcmp(MD5_CONSTANTS, p, sizeof(MD5_CONSTANTS[0])) == 0)
	{
		ret = 0;
		
		for (i = 0; i < sizeof(MD5_CONSTANTS) / sizeof(MD5_CONSTANTS[0]); i++)
		{
			if (memcmp(&MD5_CONSTANTS[i], p + i * sizeof(MD5_CONSTANTS[0]), sizeof(MD5_CONSTANTS[0])) != 0)
			{
				ret = -1;
			}
		}
	}
	
	return ret;
}
