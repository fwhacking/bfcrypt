/*
 * Copyright (C) 2011 <fwhacking|gmail:com>
 *
 * This is free software, licensed under the GNU General Public License v2.
 * See /LICENSE for more information.
 *
 */

#ifndef _SHA256_H_
#define _SHA256_H_

/*
 * http://csrc.nist.gov/publications/fips/fips180-2/fips180-2.pdf
 */

int find_sha256(char *base, size_t offset);
int find_sha256_init(char *p);
int find_sha256_constants(char *p);

/*
 * Initial hash value. These words were obtained by taking the first
 * thirty-two bits of the fractional parts of the square roots of the
 * first eight prime numbers.
 */
static uint32_t SHA256_INIT[8] =
{
	0x6a09e667L, 0xbb67ae85L, 0x3c6ef372L, 0xa54ff53aL,
	0x510e527fL, 0x9b05688cL, 0x1f83d9abL, 0x5be0cd19L
};

/*
 * Sequence of sixty-four constants. These words represent the first
 * thirty-two bits of the fractional parts of the cube roots of the
 * first sixty-four prime numbers.
 */
static uint32_t SHA256_CONSTANTS[64] =
{
	0x428a2f98L, 0x71374491L, 0xb5c0fbcfL, 0xe9b5dba5L,
	0x3956c25bL, 0x59f111f1L, 0x923f82a4L, 0xab1c5ed5L,
	0xd807aa98L, 0x12835b01L, 0x243185beL, 0x550c7dc3L,
	0x72be5d74L, 0x80deb1feL, 0x9bdc06a7L, 0xc19bf174L,
	0xe49b69c1L, 0xefbe4786L, 0x0fc19dc6L, 0x240ca1ccL,
	0x2de92c6fL, 0x4a7484aaL, 0x5cb0a9dcL, 0x76f988daL,
	0x983e5152L, 0xa831c66dL, 0xb00327c8L, 0xbf597fc7L,
	0xc6e00bf3L, 0xd5a79147L, 0x06ca6351L, 0x14292967L,
	0x27b70a85L, 0x2e1b2138L, 0x4d2c6dfcL, 0x53380d13L,
	0x650a7354L, 0x766a0abbL, 0x81c2c92eL, 0x92722c85L,
	0xa2bfe8a1L, 0xa81a664bL, 0xc24b8b70L, 0xc76c51a3L,
	0xd192e819L, 0xd6990624L, 0xf40e3585L, 0x106aa070L,
	0x19a4c116L, 0x1e376c08L, 0x2748774cL, 0x34b0bcb5L,
	0x391c0cb3L, 0x4ed8aa4aL, 0x5b9cca4fL, 0x682e6ff3L,
	0x748f82eeL, 0x78a5636fL, 0x84c87814L, 0x8cc70208L,
	0x90befffaL, 0xa4506cebL, 0xbef9a3f7L, 0xc67178f2L
};

#endif // _SHA256_H_
