/*
 * ==========================================================================
 *
 *       Filename:  bi_help.c
 *
 *    Description:  blockchain load function
 *
 *        Version:  1.0
 *        Created:  02.05.2025 13:18:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "cli.h"

/**
 * bi_load - load blockchain from given file
 * @bc: current blockchain
 * @block: current block
 * @wallet: current wallet
 * @args1: args1
 * @args2: args2
 *
 * Return: 0 on success 1 on failure
 */
int bi_load(blockchain_state_t *state, char* args1, char *args2)
{
	(void)block, (void)wallet, (void)args2;

	if (!args1)
	{
		printf("Usage: load [path]\nMissing path argument :(\n");
		return (1);
	}
	blockchain_destroy(bc);
	bc = blockchain_deserialize(args1);

	if (!bc)
	{
		printf("Unable to load from the file %s\n", args1);
		return (1);
	}

	printf("Successfully loaded blockchain from file %s\n", args1);
	printf("Check blockchain state with command : info\n");
	return (0);
}

