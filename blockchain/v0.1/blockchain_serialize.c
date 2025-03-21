/*
 * ==========================================================================
 *
 *       Filename:  blockchain_serialize.c
 *
 *    Description:  serializes a Blockchain into a file
 *
 *        Version:  1.0
 *        Created:  14.03.2025 12:28:06
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
 * record_blocks_into_fd - record given node into given fd
 * @node: node to write
 * @index: index of the node in the chain
 * @arg: void ptr to fd
 *
 * Return: 0 on success 1 on failure
 */
int record_block_into_fd(llist_node_t node, unsigned int index, void *arg)
{
	int fd;

	(void)index;
	if (!node || !arg)
		return (1);
	fd = (int)arg;
	write(fd, (void *)&block->info, sizeof(block->info));
	write(fd, (void *)&block->data.len, sizeof(block->data.len));
	write(fd, block->data.buffer, block->data.len);
	write(fd, block->hash, sizeof(block->hash));
	return (0);
}

/**
 * blockchain_serialize - serialize a blockchain into a file
 * @blockchain: blockchain to serialize
 * @path: path of the file to save the blockchain
 *
 * Return: 0 on success -1 on failure
 */
int blockchain_serialize(blockchain_t const *blockchain,
		char const *path)
{
	int fd, number_of_blocks, endian;

	fd = open(path, O_CREAT | O_TRUNC | O_WRONLY | 644);
	if (fd == -1)
	{
		fprintf(stderr, "Cannot open file:%s\n", path);
		return (-1);
	}

	number_of_blocks = llist_size(blockchain->chain);
	endian = _get_endianness();
	write(fd, HBLK_MAGIC VERSION, 7);
	write(fd, endian, sizeof(endian));
	write(fd, number_of_blocks, sizeof(number_of_blocks));

	if (llist_for_each(blockchain->chain, record_block_into_fd, fp))
	{
		fprintf(stderr, "Error when trying to write block into fd\n");
		close(fd);
		return (-1);
	}

	close(fd);
	return (0);
}
