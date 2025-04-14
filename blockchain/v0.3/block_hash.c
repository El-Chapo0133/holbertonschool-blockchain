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


int hash_tx(llist_node_t node, unsigned int id, void *arg)
{
	memcpy(*(uint8_t **)arg, ((transaction_t *)node)->id, SHA256_DIGEST_LENGTH);
	*(uint8_t **)arg += SHA256_DIGEST_LENGTH;
	return (0);
	(void)idx;
}

/*
 * block_hash - computes the hash of a block_t
 *
 * Return: ptr to the buffer which contains the hash
 */
uint8_t *block_hash(block_t const *block,
		uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	int tx_len, target_len, offset = sizeof(block->info) + block->data.len;
	int8_t *hash_target;

	if (!llist_is_empty(block->transactions))
		tx_len = llist_size(block->transactions);
	target_len = offset + 32 * tx_len;
	hash_target = malloc(target_len);
	if (!hash_target)
		return (NULL);
	memcpy(hash_target, &block->info, offset);
	hash_target += offset;
	llist_for_each(block->transactions, hash_tx, &hash_target);
	sha256((int8_t const *)block, len, hash_buf);
	free(hash_target);
	return (hash_buf);
}
