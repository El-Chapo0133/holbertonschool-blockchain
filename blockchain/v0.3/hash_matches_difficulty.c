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
	uint32_t zeroBitsNeeded = difficulty;
	uint32_t zeroBitsCount = 0;
	int i, bit;

	for (i = 0; i < SHA256_DIGEST_LENGTH; ++i)
	{
		for (bit = 7; bit >= 0; --bit)
		{
			if ((hash[i] >> bit) & 1)
			{
				return (zeroBitsCount >= zeroBitsNeeded ? 1 : 0);
			}
			else
			{
				zeroBitsCount++;
			}
		}
	}

	return (zeroBitsCount >= zeroBitsNeeded ? 1 : 0);
}
