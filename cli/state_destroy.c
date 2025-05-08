/*
 * ==========================================================================
 *
 *       Filename:  state_destroy.c
 *
 *    Description:  destroy a state_t
 *
 *        Version:  1.0
 *        Created:  05/08/25 10:09:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Leveque 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "cli.h"

void state_destroy(state_t *state)
{
	state->argc = 0;
	free(state->argv);
	state->argv = NULL;
	free(state->line);
	state->line = NULL;
	state->linesz = 0;
	EC_KEY_free(state->wallet);
	state->wallet = NULL;
	blockchain_destroy(state->blockchain);
	state->blockchain = NULL;
	llist_destroy(state->tx_pool, 1, (node_dtor_t)transaction_destroy);
	state->tx_pool = NULL;
}

