/*
 * ==========================================================================
 *
 *       Filename:  bi_help.c
 *
 *    Description:  blockchain info function
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
 * sum_unspent_amounts - program that iterates over unspent
 * transaction outputs and accumulates their amounts
 * @node: a pointer to the unspent_tx_out_t structure
 *        (represents an unspent transaction output)
 * @idx: the index of the current item in the list (unused)
 * @arg: a pointer to a long unsigned int where the accumulated total is stored
 *
 * Return: 0 (success)
 */

static int sum_unspent_amounts(void *node,
			       unsigned int idx __attribute__((unused)), void *arg)
{
	unspent_tx_out_t *unspent_tx_out = node;
	unsigned long int *accumulator = arg;

	*accumulator += unspent_tx_out->out.amount;

	return (0);
}



/**
 * cli_info - program that provides a command line interface
 * summary of the blockchain state
 * @state: a pointer to the state_t structure
 *         containing all blockchain information
 *
 * Return: EXIT_SUCCESS on successful execution,
 *         or 2 if there are too many arguments
 */

int cli_info(state_t *state)
{
	unsigned long int coins = 0;

	if (state->argc > 1)
	{
		fprintf(stderr, "%s: too many arguments\n", state->argv[0]);
		return ((state->status = 2));
	}
	llist_for_each(state->blockchain->unspent, sum_unspent_amounts, &coins);

	fprintf(stdout, "Blocks:  %d\n",
		llist_size(state->blockchain->chain));
	fprintf(stdout, "UTXOs:   %d\n",
		llist_size(state->blockchain->unspent));
	fprintf(stdout, "TX Pool: %d\n",
		llist_size(state->tx_pool));
	fprintf(stdout, "Coins:   %lu\n", coins);

	return ((state->status = EXIT_SUCCESS));
}
