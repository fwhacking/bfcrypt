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
#include "blowfish.h"

int find_blowfish(char *base, size_t offset)
{
	unsigned int i;
	
	if (find_blowfish_parray(base + offset) == 0)
	{
		printf("Blowfish P-array  (0x%08x) found at 0x%08lx\n", BLOWFISH_PARRAY[0], (unsigned long) offset);
	}

	for (i = 0; i < 4; i++)
	{
		if (find_blowfish_sbox(base + offset, i) == 0)
		{
			printf("Blowfish S-box[%d] (0x%08x) found at 0x%08lx\n", i, BLOWFISH_SBOX[i][0], (unsigned long) offset);
		}
	}
	
	return 0;
}

int find_blowfish_parray(char *p)
{
	int ret = -1;
	unsigned int i;
	
	if (memcmp(BLOWFISH_PARRAY, p, sizeof(BLOWFISH_PARRAY[0])) == 0)
	{
		ret = 0;
		
		for (i = 0; i < sizeof(BLOWFISH_PARRAY) / sizeof(BLOWFISH_PARRAY[0]); i++)
		{
			if (memcmp(&BLOWFISH_PARRAY[i], p + i * sizeof(BLOWFISH_PARRAY[0]), sizeof(BLOWFISH_PARRAY[0])) != 0)
			{
				ret = -1;
			}
		}
	}
	
	return ret;
}

int find_blowfish_sbox(char *p, int n)
{
	int ret = -1;
	unsigned int i;
	
	if (memcmp(BLOWFISH_SBOX[n], p, sizeof(BLOWFISH_SBOX[n][0])) == 0)
	{
		ret = 0;
		
		for (i = 0; i < sizeof(BLOWFISH_SBOX[n]) / sizeof(BLOWFISH_SBOX[n][0]); i++)
		{
			if (memcmp(&(BLOWFISH_SBOX[n][i]), p + i * sizeof(BLOWFISH_SBOX[n][0]), sizeof(BLOWFISH_SBOX[n][0])) != 0)
			{
				ret = -1;
			}
		}
	}
	
	return ret;
}
