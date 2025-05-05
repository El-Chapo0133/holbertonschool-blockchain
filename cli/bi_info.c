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

/*
 * sum_unspent_amounts - workaround to sum a llist amount
 * @node: current node
 * @idx: id of the current node
 * @arg: passed arg
 */
static void sum_unspent_amounts(void *node, unsigned int idx, void *arg)
{
	unspent_tx_out_t *unspent_tx_out = node;
	unsigned long int *accumulator = arg;

	*accumulator += unspent_tx_out->out.amount;
	(void)idx;
}

/**
 * bi_info - display info about the current blockchain
 * @state: current state of the blockchain
 * @args1: args1
 * @args2: args2
 *
 * Return: 0 on success 1 otherwise
 */
int bi_info(blockchain_state_t *state, char* args1, char *args2)
{
	unsigned long int coins = 0;

	(void)args1, (void)args2;

	llist_for_each(state->blockchain->unspent, sum_unspent_amounts, &coins);

	fprintf(stdout, "Blocks:  %d\n",
		llist_size(state->blockchain->chain));
	fprintf(stdout, "UTXOs:   %d\n",
		llist_size(state->blockchain->unspent));
	fprintf(stdout, "TX Pool: %d\n",
		llist_size(state->tx_pool));
	fprintf(stdout, "Coins:   %lu\n", coins);
					
	return (0);
	
}
