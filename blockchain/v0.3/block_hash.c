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
	int tx_len, target_len, index, offset;
	int8_t *hash_target;
	transaction_t *token;

	if (block->transactions)
		tx_len = llist_size(block->transactions);
	target_len = offset + 32 * tx_len;
	return (sha256((int8_t const *)block, len, hash_buf));
}
