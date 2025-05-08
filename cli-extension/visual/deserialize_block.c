/*
 * ==========================================================================
 *
 *       Filename:  deserialize_block.c
 *
 *    Description:  deserialize a block from the socket
 *
 *        Version:  1.0
 *        Created:  05/08/25 13:07:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Leveque 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "cli_visual.h"

block_t *deserialize_block(char *buffer)
{
	block_t *block;
	int offset = 0, transactions_len;
	//llist_t *transactions = llist_create(MT_SUPPORT_FALSE);

	block = malloc(sizeof(block_t));
	if (!block /*|| !transactions*/)
	{
		fprintf(stderr, "Cannot allocate new block or transaction\n");
		//llist_destroy(transactions, 0, NULL);
		return (NULL);
	}

	memcpy(block, buffer, 24);
	offset += 24;
	memcpy(block->info.prev_hash, buffer + offset, SHA256_DIGEST_LENGTH);
	offset += SHA256_DIGEST_LENGTH;
	memcpy(block->hash, buffer + offset, SHA256_DIGEST_LENGTH);
	offset += SHA256_DIGEST_LENGTH;
	memcpy(&transactions_len, buffer + offset, 4);
	offset += 4;

	printf("%d\n", block->info.difficulty);
	printf("%s\n", block->hash);

	return (block);
}
