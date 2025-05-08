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
static void parse_line(state_t *state)
{
	char *linedup = strdup(state->line);
	char **tokens = NULL;
	char *token = NULL;
	int ntokens = 0;

	state->argc = 0;
	state->argv = NULL;

	if (linedup)
	{
		token = strtok(linedup, BLANK);

		if (token)
		{
			do {
				ntokens += 1;
				token = strtok(NULL, BLANK);
			} while (token);
		}
		free(linedup);

		tokens = calloc(ntokens + 1, sizeof(*tokens));
		ntokens = 0;
		token = strtok(state->line, BLANK);

		if (token)
		{
			do {
				tokens[ntokens] = token;
				ntokens += 1;
				token = strtok(NULL, BLANK);
			} while (token);
		}
		state->argc = ntokens;
		state->argv = tokens;
	}
}

/**
 * display_intro_message - display the intro message
 */
void display_intro_message(void)
{
	fprintf(stdout, "Welcome to the cli blockchain base program !\n");
	fprintf(stdout, "Use the [help] command to display the help table\n");
}

/**
 * main - main function, are you dumb or what
 *
 * Return: exit code, what were you expecting ?
 */
int main(void)
{
	state_t state = {0};
	int (*function)(state_t *);
        int status;
        ssize_t nread;

        state_init(&state);
	connect_socket();
        display_intro_message();

	while (1)
	{
                fprintf(stdout, PROMPT);
		nread = getline(&state.line, &state.linesz, stdin);
                if (nread < 1)
                        break;

		parse_line(&state);

                if (state.argc < 1)
                        continue;
		function = gumball(state.argv[0]);
		if (function)
			function(&state);
		else
			fprintf(stdout, "Command unrecognised :(\n");

	}

	close_socket();
        status = state.status;
        state_destroy(&state);
	return (status);
}
