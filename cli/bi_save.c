/*
 * ==========================================================================
 *
 *       Filename:  bi_help.c
 *
 *    Description:  blockchain save function
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
 * bi_save - save blockchain from given file
 * @bc: current blockchain
 * @block: current block
 * @wallet: current wallet
 * @args1: args1
 * @args2: args2
 *
 * Return: 0 on success 1 on failure
 */
int bi_save(blockchain_state_t *state, char* args1, char *args2)
{
	(void)args2;

	if (!args1)
	{
		printf("Usage: save [path]\nMissing path argument :(\n");
		return (1);
	}

	if (blockchain_serialize(&state->blockchain, args1) == -1)
	{
		printf("Unable to save the blockchain into file %s\n", args1);
		return (1);
	}

	printf("Successfully savec blockchain into file %s\n", args1);
	return (0);
}

