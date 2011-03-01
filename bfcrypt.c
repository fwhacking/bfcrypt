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
#include "md5.h"
#include "sha256.h"
#include "crc32.h"
#include "des.h"

static void print_usage(const char *name)
{
	printf("Usage: %s file\n", name);
}

int main(int argc, char **argv)
{
	FILE *fd;
	char *start;
	size_t size;
	size_t offset;

	if (argc != 2)
	{
		print_usage(argv[0]);
		exit(1);
	}

	fd = fopen(argv[1], "rb");
	if (fd == NULL)
	{
		printf("Could not read the file '%s'\n", argv[1]);
		print_usage(argv[0]);
		exit(1);
	}

	size = fseek(fd, 0L, SEEK_END);
	size = ftell(fd);
	// printf("File size : %ld bytes\n\n", size);
	fseek(fd, 0L, SEEK_SET);

	start = malloc(size);

	fread(start, size, 1, fd);
	fclose(fd);

	for (offset = 0; offset < size; offset++)
	{
		find_blowfish(start, offset);
		find_md5(start, offset);
		find_sha256(start, offset);
		find_crc32(start, offset);
		find_des(start, offset);
	}

	free(start);

	exit(0);
}
