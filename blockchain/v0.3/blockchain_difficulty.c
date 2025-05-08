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

/**
 * blockchain_difficulty - computes the difficulty to assign to a potential
 * next Block in the Blockchain
 * @blockchain: blockchain to work with
 *
 * Return: difficulty for the next block
 */
uint32_t blockchain_difficulty(blockchain_t const *blockchain)
{
	block_t *last_block, *adjusted_block;
	uint64_t expected_time, actual_time;
	size_t blockchain_size = llist_size(blockchain->chain);

	if (!blockchain || blockchain_size < 2)
	{
		fprintf(stderr, "Invalid blockchain\n");
		return (0);
	}
	last_block = llist_get_node_at(blockchain->chain, blockchain_size - 1);

	if (!last_block)
	{
		fprintf(stderr, "Failed to retrieve the last block\n");
		return (0);
	}

	if (last_block->info.index % DIFFICULTY_ADJUSTMENT_INTERVAL == 0 &&
	last_block->info.index != 0)
	{
		adjusted_block = llist_get_node_at(blockchain->chain,
						   blockchain_size -
						   DIFFICULTY_ADJUSTMENT_INTERVAL);
		if (!adjusted_block)
		{
			fprintf(stderr, "Failed to retrieve the adjusted block\n");
			return (0);
		}

		expected_time = BLOCK_GENERATION_INTERVAL * DIFFICULTY_ADJUSTMENT_INTERVAL;
		actual_time = last_block->info.timestamp - adjusted_block->info.timestamp;

		if (actual_time < expected_time / 2)
			return (last_block->info.difficulty + 1);

		else if (actual_time > expected_time * 2)
			return (last_block->info.difficulty > 0 ?
			last_block->info.difficulty - 1 : 0);
	}
	return (last_block->info.difficulty);
}

