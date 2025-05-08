/*
 * ==========================================================================
 *
 *       Filename:  block_hash.c
 *
 *    Description:  computes the hash of a Block
 *
 *        Version:  1.0
 *        Created:  14.03.2025 12:24:37
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
 * block_hash - computes the hash of a block_t
 *
 * Return: ptr to the buffer which contains the hash
 */
uint8_t *block_hash(block_t const *block,
		uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	size_t data_size;
	size_t offset;
	uint8_t *data_to_hash;
	int i;
	transaction_t *tx;

	if (!block || !hash_buf)
		return (NULL);

	data_size = sizeof(block->info) + block->data.len;

	for (i = 0; i < llist_size(block->transactions); i++)
	{
		tx = llist_get_node_at(block->transactions, i);
		data_size += SHA256_DIGEST_LENGTH;
	}

	data_to_hash = malloc(data_size);

	if (!data_to_hash)
		return (NULL);

	memcpy(data_to_hash, &block->info, sizeof(block->info));
	memcpy(data_to_hash + sizeof(block->info),
	       block->data.buffer, block->data.len);

	offset = sizeof(block->info) + block->data.len;

	for (i = 0; i < llist_size(block->transactions); i++)
	{
		tx = llist_get_node_at(block->transactions, i);
		memcpy(data_to_hash + offset, tx->id, SHA256_DIGEST_LENGTH);
		offset += SHA256_DIGEST_LENGTH;
	}

	SHA256(data_to_hash, data_size, hash_buf);

	free(data_to_hash);

	return (hash_buf);
}
