/*
 * ==========================================================================
 *
 *       Filename:  blockchain_create.c
 *
 *    Description:  creates a Blockchain structure, and initializes it
 *
 *        Version:  1.0
 *        Created:  14.03.2025 09:19:42
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
 * blockchain_create - create a blockchain_t
 *
 * Return: ptr to newly blockchain struct
 */
blockchain_t *blockchain_create(void)
{
	block_t *block;
	blockchain_t *blockchain;
	llist_t *list = llist_create(MT_SUPPORT_TRUE);
	int index = 0;

	blockchain = malloc(sizeof(blockchain_t));
	block = malloc(sizeof(block_t));
	if (!blockchain || !block)
	{
		fprintf(stderr, "cannot allocate for chain or block");
		free(blockchain), free(block), llist_destroy(list, 1, NULL);
		return (NULL);
	}

	/* meta data settings */
	(block->info).index = GENESIS_INDEX;
	(block->info).difficulty = GENESIS_DIFFICULTY;
	(block->info).timestamp = GENESIS_TIMESTAMP;
	(block->info).nonce = GENESIS_NONCE;
	for (index = 0; index < SHA256_DIGEST_LENGTH; index++)
		(block->info).prev_hash[index] = GENESIS_PREV_HASH;
	/* data settings */
	block->data.len = GENESIS_LEN;
	memcpy(block->data.buffer, GENESIS_BUFFER, GENESIS_LEN);
	/* hash set */
	memcpy(block->hash, GENESIS_HASH, SHA256_DIGEST_LENGTH);

	if (llist_add_node(list, block, ADD_NODE_FRONT))
	{
		fprintf(stderr, "Cannot add node in the llist");
		free(blockchain), free(block), llist_destroy(list, 1, NULL);
		return (NULL);
	}

	blockchain->chain = list;
	return (blockchain);
}



