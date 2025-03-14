/*
 * ==========================================================================
 *
 *       Filename:  blockchain_destroy.c
 *
 *    Description:  deletes an existing Blockchain
 *			along with all the Blocks it contains
 *
 *        Version:  1.0
 *        Created:  14.03.2025 11:50:52
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
 * blockchain_destroy - destroy a blockchain and all it's blocks
 * @blockchain: blockchain to destroy
 */
void blockchain_destroy(blockchain_t *blockchain)
{
	block_t *block;

	block = llist_pop(blockchain->chain);
	while (block)
	{
		block_destroy(block);
		block = llist_pop(blockchain->chain);
	}
	llist_destroy(clockchain->chain, 0, NULL);
	free(blockchain);
}
