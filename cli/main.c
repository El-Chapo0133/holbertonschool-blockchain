/*
 * ==========================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  cli base main file
 *
 *        Version:  1.0
 *        Created:  04/30/25 12:07:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Leveque 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "cli.h"


command_t *parse_line(char *line)
{
	int first = 1;
	char *line = strtok(line, "\n");
	command_t command = malloc(sizeof(command_t));
	
	if (!command)
		return (NULL);
	
	command->cmd = strtok(line, " ");
	command->args1 = strtok(NULL, " ");
	command->args2 = strtok(NULL, " ");

	return (command);
}


void display_intro_message(void)
{
	fprintf(stdout, "Welcome to the cli blockchain base program !");
}


int main(void)
{
	EC_KEY *wallet = ec_create();
	blockchain_t *blockchain = blockchain_create();
	block_t *block = llist_get_head(blockchain->chain);
	commant_t command;
	char *line;
	ssize_t line_len;

	block = block_create(block, (int8_t *)"Holberton", 9);

	while (1)
	{
		if (getline(&line, &line_len, stdin) == 0)
			break;
		command = parse_line(line);
		if (!command)
			fprintf(stdout, "Cannot parse given line\n");

		function = gumball(command->cmd);
		if (function)
			function(&blockchain, &block, &wallet,
					command->args1, command->args2);
		else
			fprintf(stdout, "Command unrecognised :(\n");

	}

	block_destroy(block);
	blockchain_destroy(blockchain);
	EC_KEY_free(wallet);
	if (line)
		free(line), free(command);

	return (0);
}

