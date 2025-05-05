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
int (*gumball(char *cmd))(blockchain_t **, block_t **, EC_KEY **, char *, char *)
{
	int index;
	gumball_t pot = {
		{ "help", &bi_help },
		{ "wallet_load", &bi_wallet_load },
		{ "wallet_save", &bi_wallet_save },
		{ "send", &bi_send },
		{ "mine", &bi_mine },
		{ "info", &bi_info },
		{ "load", &bi_load },
		{ "save", &bi_save },
	}

	if (!cmd)
		return (NULL);

	for (index = 0; index < 8; index++)
	{
		if (!strcmp(cmd, pot[index].cmd))
			return (pot[index].f);
	}

	return (NULL);
}
