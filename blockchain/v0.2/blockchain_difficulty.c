/*
 * ==========================================================================
 *
 *       Filename:  blockchain_difficulty.c
 *
 *    Description: computes the difficulty to assign to a potential
 *				next Block in the Blockchain 
 *
 *        Version:  1.0
 *        Created:  28.03.2025 13:14:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "blockchain.h"

/*
 * blockchain_difficulty - computes the difficulty to assign to a potential
 * next Block in the Blockchain
 * @blockchain: blockchain to work with
 */
uint32_t blockchain_difficulty(blockchain_t const *blockchain)
{
	uint64_t elapsed, expected;
	block_t *last, *last_adjusted;

	last = llist_get_tail(blockchain->chain);
	if (!last || last->info.index == 0 ||
		last->info.index % DIFFICULTY_ADJUSTMENT_INTERVAL != 0)
		return (last->info.difficulty);

	last_adjusted = llist_get_node_at(blockchain->chain,
			last->info.index + 1 - DIFFICULTY_ADJUSTMENT_INTERVAL);
	elapsed = last->info.timestamp - last_adjusted->info.timestamp;
	expected = BLOCK_GENERATION_INTERVAL * DIFFICULTY_ADJUSTMENT_INTERVAL;

	if ((elapsed * 2) < expected)
		return (last->info.difficulty + 1);
	else if (elapsed > expected * 2)
		return (last->info.difficulty - 1);
	return (last->info.difficulty);
}

