/*
 * ==========================================================================
 *
 *       Filename:  block_destroy.c
 *
 *    Description:  deletes an existing Block
 *
 *        Version:  1.0
 *        Created:  14.03.2025 10:59:08
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
 * block_destroy - destroy a given block
 * @block: block to destroy
 */
void block_destroy(block_t *block)
{
	if (!block)
		return;
	llist_destroy(block->transactions, 1,
		(node_dtor_t)transaction_transaction);
	free(block);
}
