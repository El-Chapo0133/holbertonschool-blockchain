/*
 * ==========================================================================
 *
 *       Filename:  block_is_valid.c
 *
 *    Description:  checks if this and previous block are valid
 *
 *        Version:  1.0
 *        Created:  28.03.2025 10:01:32
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
 * check_transaction - check if all transactions are valid
 * @block: ptr to block containing transactions
 * @all_unspent: ptr to llist of all unspent transactions
 *
 * Return: 0 if valid, 1 otherwise
 */
int check_transaction(block_t const *block, llist_t *all_unspent)
{
	int index;
	transaction_t *t;

	for (index = 0; index < llist_size(block->transactions); index++)
	{
		t = llist_get_node_at(block->transactions, index);
		if (index == 0 && !coinbase_is_valid(t, block->info.index))
			return (1);
		else if (!transaction_is_valid(t, all_unspent))
			return (1);
	}
	if (index == 0)
		return (1);
	return (0);
}


/**
 * block_is_valid - checks if this and previous block are valid
 * @block: pointer to this block in the chain
 * @prev_block: pointer to previous block in the chain or NULL
 * @all_unspent: ptr to all unspent transactions
 *
 * Return: 0 if valid else 1 if invalid
 */
int block_is_valid(block_t const *block, block_t const *prev_block,
		llist_t *all_unspent)
{
	uint8_t hash_buf[SHA256_DIGEST_LENGTH] = {0};
	block_t *genesis;
	int index;

	genesis = malloc(sizeof(block_t));
	if (!genesis)
	{
		fprintf(stderr, "cannot allocate for genesis\n");
		return (1);
	}

	(genesis->info).index = GENESIS_INDEX;
	(genesis->info).difficulty = GENESIS_DIFFICULTY;
	(genesis->info).timestamp = GENESIS_TIMESTAMP;
	(genesis->info).nonce = GENESIS_NONCE;
	for (index = 0; index < SHA256_DIGEST_LENGTH; index++)
		(genesis->info).prev_hash[index] = GENESIS_PREV_HASH;
	genesis->data.len = GENESIS_LEN;
	memcpy(genesis->data.buffer, GENESIS_BUFFER, GENESIS_LEN);
	memcpy(genesis->hash, GENESIS_HASH, SHA256_DIGEST_LENGTH);


	if (!block || (!prev_block && block->info.index != 0))
		return (1);
	if (block->info.index == 0)
		return (memcmp(block, &genesis, sizeof(genesis)));
	if (block->info.index != prev_block->info.index + 1)
		return (1);
	if (!block_hash(prev_block, hash_buf) ||
		memcmp(hash_buf, prev_block->hash, SHA256_DIGEST_LENGTH))
		return (1);
	if (memcmp(prev_block->hash, block->info.prev_hash, SHA256_DIGEST_LENGTH))
		return (1);
	if (!block_hash(block, hash_buf) ||
		memcmp(hash_buf, block->hash, SHA256_DIGEST_LENGTH))
		return (1);
	if (block->data.len > BLOCKCHAIN_DATA_MAX)
		return (1);
	if (!hash_matches_difficulty(block->hash, block->info.difficulty))
		return (1);
	if (check_transaction(block, all_unspent))
		return (1);
	return (0);
}
