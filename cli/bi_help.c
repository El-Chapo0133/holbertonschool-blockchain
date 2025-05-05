/*
 * ==========================================================================
 *
 *       Filename:  bi_help.c
 *
 *    Description:  blockchain help function
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

int bi_help(blockchain_state_t *state, char* args1, char *args2)
{
	(void)state, (void)args1, (void)args2;

	printf("|> HELP table\n");
	printf(" | Name        | Args1  | Args2   | Description                              |\n");
	printf(" | ----------- | ------ | ------- | ---------------------------------------- |\n");
	printf(" | help        | NULL   | NULL    | Print help table                         |\n");
	printf(" | load        | path   | NULL    | Load the blockchain from a file          |\n");
	printf(" | save        | path   | NULL    | Save the blockchain into a file          |\n");
	printf(" | info        | NULL   | NULL    | Display information about the blockchain |\n");
	printf(" | mine        | NULL   | NULL    | Mine a new block                         |\n");
	printf(" | send        | amount | address | Send [amount] into [address]             |\n");
	printf(" | wallet_load | path   | NULL    | Load the wallet from a file              |\n");
	printf(" | wallet_save | path   | NULL    | Save the wallet into a file              |\n");
	printf(" +---------------------------------------------------------------------------+\n");

	return (0);
}
