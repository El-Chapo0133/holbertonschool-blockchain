/*
 * ==========================================================================
 *
 *       Filename:  block_mine.c
 *
 *    Description:  mines a Block in order to insert it in the Blockchain
 *
 *        Version:  1.0
 *        Created:  28.03.2025 10:22:48
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
 * block_mine - mines a Block in order to insert it in the Blockchain
 * @block: ptr to the block to be mined
 */
void block_mine(block_t *block)
{
	uint64_t nonce;

	do
	{
		/* update the nonce and the hash */
		block->info.nonce = nonce;
		block_hash(block, block->hash);
		nonce++;
	}
	while (hash_matches_difficulty(block->hash, block->info.difficulty));
}

