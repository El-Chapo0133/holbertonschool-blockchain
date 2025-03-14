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
	int fd;

	fd = open(path, O_CREAT | O_TRUNC | O_WRONLY | 644);
	if (fd == -1)
	{
		fprintf(stderr, "Cannot open file:%s\n", path);
		return (-1);
	}

	(void)blockchain;
	write(HBLK_MAGIC VERSION, 7, 1, fd);

	return (0);
}
