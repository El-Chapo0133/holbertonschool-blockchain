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
 * bi_wallet_load - load a wallet (key pair) from given file
 * @state: current state of the blockchain
 * @args1: args1
 * @args2: args
 *
 * Return: 0 on success 1 on failure
 */
int bi_wallet_load(blockchain_state_t *state, char* args1, char *args2)
{
	EC_KEY *wallet;

	if (!args1)
	{
		printf("Usage: wallet_load [path]\nMissing path argument :(\n");
		return (1);
	}

	wallet = ec_load(args1);
	if (!wallet)
	{
		printf("Failure to load the wallet from the file %s\n", args1);
		return (1);
	}

	EC_KEY_free(state->wallet);
	state->wallet = wallet;

	printf("Succress to load the wallet from the file %s\n", args1);
	return (0);
}
