/*
 * ==========================================================================
 *
 *       Filename:  gumball.c
 *
 *    Description:  matches a cmd with a functions
 *
 *        Version:  1.0
 *        Created:  04/30/25 12:45:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Leveque 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "cli.h"

/*
 * gumball - matches a cmd with a functions from a set list
 * @cmd: command to match
 *
 * Return: ptr to correct function or NULL 
 */
int (*gumball(char *cmd))(state_t *)
{
	int index;
	gumball_t pot[] = {
		{ "help", &cli_help },
		{ "wallet_load", &cli_wallet_load },
		{ "wallet_save", &cli_wallet_save },
		{ "send", &cli_send },
		{ "mine", &cli_mine },
		{ "info", &cli_info },
		{ "load", &cli_load },
		{ "save", &cli_save },
		{ "exit", &cli_exit },
	};

	if (!cmd)
		return (NULL);

	for (index = 0; index < 9; index++)
	{
		if (!strcmp(cmd, pot[index].cmd))
			return (pot[index].f);
	}


	return (NULL);
}
