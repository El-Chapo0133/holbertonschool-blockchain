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
 * serialize_block_transactions - serialize the transactions
 * @b: serialized_block_t
 * @block: block_t
 *
 * Return: 1 on success 0 on failure
 */
int serialize_block_transactions(serialized_block_t *b, block_t *block,
                size_t offset)
{
	(void)b, (void)block, (void)offset;
	return (1);
}


/**
 * serialize_block - serialize a block into a char*
 * @block: block to serialize
 *
 * Return: ptr to serialized_block_t or NULL
 */
serialized_block_t *serialize_block(block_t *block)
{
	serialized_block_t *serialized_block;
	int transaction_len;
	size_t offset = 0;

	serialized_block = malloc(sizeof(serialized_block_t));
	if (!serialized_block) /* uh oh :( */
	{
		fprintf(stderr, "Cannot allocate serialized_block_t :(\n");
		return (NULL);
	}
	serialized_block->len = 0;

        memcpy(serialized_block->buffer, &block->info, sizeof(block_info_t));
        offset += sizeof(block_info_t);
	memcpy(serialized_block->buffer + offset, block->hash, SHA256_DIGEST_LENGTH);
	offset += SHA256_DIGEST_LENGTH;
	transaction_len = llist_size(block->transactions);
	memcpy(serialized_block->buffer + offset, &transaction_len, sizeof(int));
	offset += sizeof(int);

	if (!serialize_block_transactions(serialized_block, block, offset))
	{ /* uh oh :( put 0 in transaction_len */
		fprintf(stderr, "Cannot serialize transactions :(\n");
		memcpy(serialized_block->buffer + offset, 0, 4);
	}
	serialized_block->len += offset;

#ifdef DEBUG
	printf("Length of serialized block array: %d\n", serialized_block->len);
#endif
	return (serialized_block);
}
