/*
 * ==========================================================================
 *
 *       Filename:  blockchain_deserialize.c
 *
 *    Description:  deserializes a Blockchain from a file
 *
 *        Version:  1.0
 *        Created:  21.03.2025 15:32:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "blockchain.h"

#define CLEAN_UP (free(list), close(fd))
#define CLEAN_UP_BLOCKS (free(block), llist_destroy(list, 1, NULL))
#define CHECK_ENDIAN(x) (endian ? SWAPENDIAN(x) : (void)0)


/**
 * deserialize_blocks - deserialize all the blocks from the given fd
 * @fd: fd to read from
 * @size: amount of blocks
 * @endian: current endian
 *
 * Return: llist_t or NULL
 */
llist_t deserialize_blocks(int fd, uint32_t size, uint8_t endian)
{
	block_t *block;
	llist_t *list = llist_create(MT_SUPPORT_TRUE);
	uint32_t index;

	if (!list)
		return (NULL);
	for (index = 0; index < size; index++)
	{
		block = malloc(sizeof(block_t));
		if (!block)
			return (CLEAN_UP, NULL);
		if (read(fd, &(block->info), sizeof(block->info))
				!= sizeof(block->info))
			return (CLEAN_UP, NULL);
		CHECK_ENDIAN(block->info.index);
		CHECK_ENDIAN(block->info.difficulty);
		CHECK_ENDIAN(block->info.timestamp);
		CHECK_ENDIAN(block->info.nonce);
		if (read(fd, &(block->data.len), 4) != 4)
			return (CLEAN_UP_BLOCKS, NULL);
		CHECK_ENDIAN(block->data.len);
		if (read(fd, block->data.buffer, block->data.len)
				!= block->data.len)
			return (CLEAN_UP_BLOCKS, NULL);
		if (read(fd, block->hash, SHA256_DIGEST_LENGTH)
				!= SHA256_DIGEST_LENGTH)
			return (CLEAN_UP_BLOCKS, NULL);
		if (llist_add_node(list, block, ADD_NODE_REAR))
			return (CLEAN_UP_BLOCKS, NULL);

	}
	return (list);
}


/**
 * blockchain_deserialize - deserializes a Blockchain from a file
 * @path: path to the fil to load from
 *
 * Return: ptr to blockchain_t or NULL
 */
blockchain_t *blockchain_deserialize(char const *path)
{
	int fd;
	blockchain_t *blockchain;
	uint8_t endian;
	char buffer[4096] = {0};
	uint32_t size;

	if (!path)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);

	/* check magic */
	if (read(fd, buffer, 4) != 4 || strcmp(buffer, HBLK_MAGIC))
		return (NULL);
	buffer[4] = 0;
	/* check version */
	if (read(fd, buffer, 3) != 3 || strcmp(buffer, VERSION))
		return (NULL);

	blockchain = malloc(sizeof(blockchain_t));
	if (!blockchain)
		return (NULL);
	/* get endians */
	if (read(fd, &endian, 1) != 1)
		return (NULL);
	if (read(fd, &size, 4) != 4)
		return (NULL);
	CHECK_ENDIAN(size);
	blockchain->chain = deserialize_blocks(fd, size, endian);

	close(fd);
	return (blockchain);
}

