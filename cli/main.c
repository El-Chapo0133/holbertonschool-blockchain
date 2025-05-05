/*
 * ==========================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  cli program to interact with the blockchain
 *
 *        Version:  1.0
 *        Created:  25.04.2025 14:34:43
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
 * parse_line - parse a line and return a struct command_t
 * @line: line to parse
 *
 * Return: struct command_t or NULL
 */
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

/**
 * display_intro_message - display the intro message
 */
void display_intro_message(void)
{
	fprintf(stdout, "Welcome to the cli blockchain base program !");
	fprintf(stdout, "Use the [help] command to display the help table\n");
}

/**
 * main - main function, are you dumb or what
 *
 * Return: exit code, what were you expecting ?
 */
int main(void)
{
	blockchain_state_t *state;
	block_t *block = llist_get_head(blockchain->chain);
	commant_t command;
	char *line;
	ssize_t line_len;

	state = malloc(sizeof(blockchain_state_t));
	if (!state)
	{
		fprintf(stderr, "Cannot allocated blockchain state :(\n");
		return (1);
	}
	state->blockchain = blockchain_create();
	state->block = block_create(block, (int8_t *)"Holberton", 9);
	state->wallet = ec_create();
	state->tx_pool = llist_create(MT_SUPPORT_TRUE);

	while (1)
	{
		if (getline(&line, &line_len, stdin) == 0)
			break;
		command = parse_line(line);
		if (!command)
			fprintf(stdout, "Cannot parse given line\n");

		function = gumball(command->cmd);
		if (function)
			function(&state, command->args1, command->args2);
		else
			fprintf(stdout, "Command unrecognised :(\n");

	}

	block_destroy(state->block);
	blockchain_destroy(state->blockchain);
	EC_KEY_free(state->wallet);
	llist_destroy(state->tx_pool, 1, free);
	free(state);
	if (line)
		free(line), free(command);

	return (0);
}
