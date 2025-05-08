/*
 * ==========================================================================
 *
 *       Filename:  state_init.c
 *
 *    Description:  initialize a state_t
 *
 *        Version:  1.0
 *        Created:  05/08/25 10:08:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Leveque 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "cli.h"

/**
 * state_init - initialize a state_t
 */
void state_init(state_t *state)
{
	state->status = EXIT_SUCCESS;
	state->argc = 0;
	state->argv = NULL;
	state->line = NULL;
	state->linesz = 0;
	state->wallet = ec_create();
	state->blockchain = blockchain_create();
	state->tx_pool = llist_create(MT_SUPPORT_FALSE);
}
