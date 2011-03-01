/*
 * Copyright (C) 2011 <fwhacking|gmail:com>
 *
 * This is free software, licensed under the GNU General Public License v2.
 * See /LICENSE for more information.
 *
 */

#ifndef _MD5_H_
#define _MD5_H_

int find_md5(char *base, size_t offset);
int find_md5_digest(char *p);
int find_md5_constants(char *p);

static uint32_t MD5_DIGEST[4] =
{
	0x67452301L, 0xefcdab89L, 0x98badcfeL, 0x10325476L
};

static uint32_t MD5_CONSTANTS[64] =
{
	/* round 1 */
	0xd76aa478L, 0xe8c7b756L, 0x242070dbL, 0xc1bdceeeL,
	0xf57c0fafL, 0x4787c62aL, 0xa8304613L, 0xfd469501L,
	0x698098d8L, 0x8b44f7afL, 0xffff5bb1L, 0x895cd7beL,
	0x6b901122L, 0xfd987193L, 0xa679438eL, 0x49b40821L,
	/* round 2 */
	0xf61e2562L, 0xc040b340L, 0x265e5a51L, 0xe9b6c7aaL,
	0xd62f105dL, 0x2441453L,  0xd8a1e681L, 0xe7d3fbc8L,
	0x21e1cde6L, 0xc33707d6L, 0xf4d50d87L, 0x455a14edL,
	0xa9e3e905L, 0xfcefa3f8L, 0x676f02d9L, 0x8d2a4c8aL,
	/* round 3 */
	0xfffa3942L, 0x8771f681L, 0x6d9d6122L, 0xfde5380cL,
	0xa4beea44L, 0x4bdecfa9L, 0xf6bb4b60L, 0xbebfbc70L,
	0x289b7ec6L, 0xeaa127faL, 0xd4ef3085L, 0x4881d05L,
	0xd9d4d039L, 0xe6db99e5L, 0x1fa27cf8L, 0xc4ac5665L,
	/* round 4 */
	0xf4292244L, 0x432aff97L, 0xab9423a7L, 0xfc93a039L,
	0x655b59c3L, 0x8f0ccc92L, 0xffeff47dL, 0x85845dd1L,
	0x6fa87e4fL, 0xfe2ce6e0L, 0xa3014314L, 0x4e0811a1L,
	0xf7537e82L, 0xbd3af235L, 0x2ad7d2bbL, 0xeb86d391L
};

#endif // _MD5_H_
