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
 * cli_wallet_save - program that saves the wallet to a specified file
 *
 * @state: a pointer to the state_t structure containing
 *         the command line arguments and wallet state
 *
 * Return: an integer status code indicating the outcome of the save operation,
 *         EXIT_SUCCESS on success,
 *         EXIT_FAILURE on failure
 */

int cli_wallet_save(state_t *state)
{
	if (state->argc > 2)
	{
		fprintf(stderr, "%s: too many arguments\n", state->argv[0]);
		return ((state->status = 2));
	}

	if (state->argc < 2)
	{
		fprintf(stderr, "%s: too few arguments\n", state->argv[0]);
		return ((state->status = 2));
	}

	if (!ec_save(state->wallet, state->argv[1]))
	{
		fprintf(stdout, "Failed to save wallet to %s\n",
			state->argv[1]);
		return ((state->status = EXIT_FAILURE));
	}

	fprintf(stdout, "Saved wallet to %s\n",
		state->argv[1]);

	return ((state->status = EXIT_SUCCESS));
}
