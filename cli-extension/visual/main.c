/*
 * ==========================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  main file for the blockchain visual representation
 *
 *        Version:  1.0
 *        Created:  05.05.2025 10:28:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "cli_visual.h"


int parse_request(int client_fd, char *buffer)
{
	printf("%s [%ld] from %d\n", buffer, strlen(buffer), client_fd);
	deserialize_block(buffer);
	return (1);
}



int main(int argc, char **argv)
{
	(void)argc, (void)argv;
	int server_status = start_server();

	if (server_status != 0)
	{
		fprintf(stderr, "Cannot start socket server :(\n");
		return (EXIT_FAILURE);
	}
}
