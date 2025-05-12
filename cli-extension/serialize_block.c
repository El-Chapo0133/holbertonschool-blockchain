/*
 * ==========================================================================
 *
 *       Filename:  serialize_block.c
 *
 *    Description:  serialize a block_t into a char *
 *
 *        Version:  1.0
 *        Created:  05/08/25 12:30:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Leveque 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "cli.h"

/**
 * serialize_block - serialize a block into a char*
 * @block: block to serialize
 *
 * Return: array of char
 */
char *serialize_block(block_t *block)
{
	char buffer[1024];
	int transaction_len;
	int offset = 0;

	memcpy(buffer, &block->info, sizeof(block_info_t));
	offset += sizeof(block_info_t);
	memcpy(buffer + offset, block->hash, SHA256_DIGEST_LENGTH);
	offset += SHA256_DIGEST_LENGTH;
	transaction_len = llist_size(block->transactions);
	memcpy(buffer + offset, &transaction_len, sizeof(int));
	offset += sizeof(int);


	return (strdup(buffer));
}
