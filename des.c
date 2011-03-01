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
#include "des.h"

int find_des(char *base, size_t offset)
{
	unsigned int i;

	for (i = 0; i < 2; i++)
	{
		if (find_des_keyswap(base + offset, i) == 0)
		{
			printf("DES Keyswap (0x%08x) found at 0x%08lx\n", DES_KEYSWAP[i][0], (unsigned long) offset);
		}
	}
	
	for (i = 0; i < 8; i++)
	{
		if (find_des_sbox(base + offset, i) == 0)
		{
			printf("DES S-box[%d] (0x%08x) found at 0x%08lx\n", i, DES_SBOX[i][0], (unsigned long) offset);
		}
	}
	
	return 0;
}

int find_des_keyswap(char *p, int n)
{
	int ret = -1;
	unsigned int i;
	
	if (memcmp(DES_KEYSWAP[n], p, sizeof(DES_KEYSWAP[n][0])) == 0)
	{
		ret = 0;
		
		for (i = 0; i < sizeof(DES_KEYSWAP[n]) / sizeof(DES_KEYSWAP[n][0]); i++)
		{
			if (memcmp(&(DES_KEYSWAP[n][i]), p + i * sizeof(DES_KEYSWAP[n][0]), sizeof(DES_KEYSWAP[n][0])) != 0)
			{
				ret = -1;
			}
		}
	}
	
	return ret;
}

int find_des_sbox(char *p, int n)
{
	int ret = -1;
	unsigned int i;
	
	if (memcmp(DES_SBOX[n], p, sizeof(DES_SBOX[n][0])) == 0)
	{
		ret = 0;
		
		for (i = 0; i < sizeof(DES_SBOX[n]) / sizeof(DES_SBOX[n][0]); i++)
		{
			if (memcmp(&(DES_SBOX[n][i]), p + i * sizeof(DES_SBOX[n][0]), sizeof(DES_SBOX[n][0])) != 0)
			{
				ret = -1;
			}
		}
	}
	
	return ret;
}
