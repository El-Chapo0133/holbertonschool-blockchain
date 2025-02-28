/*
 * ==========================================================================
 *
 *       Filename:  sha256.c
 *
 *    Description:  computes the hash of a sequence of bytes
 *
 *        Version:  1.0
 *        Created:  28.02.2025 10:14:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "hblk_crypto.h"

/**
 * sha256 - computes the hash of a sequence of bytes
 * @s: sequence of byte
 * @len: len of s
 * @digest: buffer for the hash
 *
 * Return: hash or NULL
 */
uint8_t *sha256(int8_t const *s, size_t len,
		uint8_t digest[SHA256_DIGEST_LENGTH])
{
	if (!s || !digest)
		return (NULL);
	/**
	 * use the given function to hash into digest
	 * and return the ptr to the digest
	 */
	return (SHA256((const unsigned char *)s, len, digest));
}
