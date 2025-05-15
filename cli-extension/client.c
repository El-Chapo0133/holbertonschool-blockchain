/*
 * ==========================================================================
 *
 *       Filename:  client.c
 *
 *    Description:  Client socket for the visual representation
 *
 *        Version:  1.0
 *        Created:  05.05.2025 10:27:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "cli.h"

static int socket_fd;

/**
 * close_socket - close the socket fd
 */
void close_socket(void)
{
	close(socket_fd);
}

/**
 * close_and_exit - close the given fd and exit(1)
 * @fd: fd to close
 * @res: addrinfo to free
 *
 * Return: void
 */
void close_and_exit(int fd, struct addrinfo *res)
{
        close(fd);
	freeaddrinfo(res);
	exit(1);
}

/**
 * connect_socket - connect to a socket and store it's fd
 */
int connect_socket(void)
{
	char host[HOST_LEN];
	struct addrinfo hints, *res;

	if (gethostname(host, HOST_LEN) == -1)
		return (EXIT_FAILURE);

	/* define socket addr infos */
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	/* define res addr infos */
	if (getaddrinfo(host, PORT, &hints, &res) != 0)
		return (EXIT_FAILURE);
	socket_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (socket_fd == -1)
		close_and_exit(socket_fd, res);

	/* connect to the sockets with the infos */
	if (connect(socket_fd, res->ai_addr, res->ai_addrlen) == -1)
	{
		fprintf(stdout, "Cannot connect to the socket %s:" PORT "\n",
                                host);
		close_and_exit(socket_fd, res);
	}
#ifdef DEBUG
	fprintf(stdout, "Socket connected to %s:" PORT, host);
#endif
	freeaddrinfo(res);
	return (0);
}

/*
 * send_message - send a message using the socket
 * @object: object to send
 * @object_len: len of the object
 *
 * Return: number of byte sent or -1 on error
 */
int send_message(char *object, size_t object_len)
{
	if (!socket_fd || socket_fd == -1)
		fprintf(stderr, "Socket is not connected\n");
#ifdef DEBUG
	printf("Bytes to send :%d\n", object_len);
#endif
	return (send(socket_fd, object, object_len, 0));
}
