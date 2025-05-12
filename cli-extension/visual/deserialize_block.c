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

	memcpy(block, buffer, sizeof(block_info_t));
	offset += sizeof(block_info_t);
	memcpy(block->hash, buffer + offset, SHA256_DIGEST_LENGTH);
	offset += SHA256_DIGEST_LENGTH;
	memcpy(&transactions_len, buffer + offset, 4);
	offset += 4;

	printf("%ld\n", block->info.timestamp);
	printf("%d\n", block->info.difficulty);
	printf("%ld\n", block->info.nonce);
	printf("%s\n", block->info.prev_hash);
	printf("%s\n", block->hash);

	return (block);
}
