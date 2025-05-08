/*
 * ==========================================================================
 *
 *       Filename:  bi_exit.c
 *
 *    Description:  exit cli
 *
 *        Version:  1.0
 *        Created:  05/08/25 13:55:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Leveque 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * ==========================================================================
 */
#include "cli.h"

int cli_exit(state_t *state)
{
	int status;

	close_socket();
        status = state->status;
        state_destroy(state);
	exit(status);
}
