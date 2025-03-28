/*
 * ==========================================================================
 *
 *       Filename:  hash_matches_difficulty.c
 *
 *    Description:  checks whether a given hash matches a given difficulty
 *
 *        Version:  1.0
 *        Created:  28.03.2025 09:01:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "blockchain.h"

/**
 * hash_matches_difficulty - checks whether a given hash matches
 * a given difficulty
 * @hash: hash to check
 * @difficulty: minimum difficulty the hash should match
 *
 * Return: 1 if difficulty matches 0 otherwise
 */
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
		uint32_t difficulty)
{
	uint32_t count = 0, index;
	uint8_t *ptr = (uint8_t *)hash;

	if (!hash)
		return (0);
	for (index = 0; index < SHA256_DIGEST_LENGTH; index++)
	{
		fprintf(stdout, "%d %d - ", (*ptr >> index), index);
		/* move ptr to next value */
		if ((*ptr >> index) == 1)
			break;
		count++;
		ptr++;
	}

	return (count >= difficulty);
}
