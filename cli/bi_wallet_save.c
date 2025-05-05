/*
 * ==========================================================================
 *
 *       Filename:  bi_wallet_load.c
 *
 *    Description:  blockchain wallet load function
 *
 *        Version:  1.0
 *        Created:  02.05.2025 13:18:35
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
 * bi_wallet_save - save a wallet (key pair) into the given file
 * @state: current state of the blockchain
 * @args1: args1
 * @args2: args2
 *
 * Return: 0 on success 1 on failure
 */
int bi_wallet_save(blockchain_state_t *state, char *args1, char *args2)
{
	if (!args1)
	{
		printf("Usage: wallet_save [path]\nMissing path argument :(\n");
		return (1);
	}

	if (!ec_save(state->wallet, args1))
	{
		printf("Failure to save the wallet into %s\n", args1);
		return (1);
	}

	printf("Success to save the wallet into the file %s\n", args1);
	return (0);
}
