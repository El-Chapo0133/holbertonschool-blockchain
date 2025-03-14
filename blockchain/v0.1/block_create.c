/*
 * ==========================================================================
 *
 *       Filename:  block_create.c
 *
 *    Description:  creates a Block structure and initializes it
 *
 *        Version:  1.0
 *        Created:  14.03.2025 10:35:07
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
 * block_create - create a block and initialize it
 * @prev: ptr to the previous block in the chain
 * @data: data of the new block
 * @data_len: len of data
 *
 * Return: ptr to new block or NULL
 */
block_t *block_create(block_t const *prev, int8_t const *data,
		uint32_t data_len)
{
	block_t *block;
	int index;

	block = malloc(sizeof(block_t));
	if (!block)
	{
		fprintf(stderr, "Cannot allocate new block");
		return (NULL);
	}

	/* block metadata settings */
	block->info.index = (prev->info).index + 1;
	block->info.difficulty = 0;
	block->info.timestamp = time(NULL);
	block->info.nonce = 0;
	for (index = 0; index < SHA256_DIGEST_LENGTH; index++)
		(block->info.prev_hash)[index] = (prev->hash)[index];
	/* block data setting */
	block->data.len = (data_len > BLOCKCHAIN_DATA_MAX ?
			BLOCKCHAIN_DATA_MAX : data_len);
	memcpy(block->data.buffer, data, block->data.len);
	return (block);
}

