#ifndef H_CLI_VISUAL
#define H_CLI_VISUAL
/*
 * ==========================================================================
 *
 *       Filename:  cli_visual.h
 *
 *    Description:  cli visual representation header file
 *
 *        Version:  1.0
 *        Created:  05.05.2025 10:28:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include <stdio.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <llist.h>

#define PORT 8080
#define BUFFER_SIZE 8192 /* 2^13 */
#define BIGGER_BUFFER_SIZE 16284 /* BUFFER_SIZE * 2 */
#define CRLF "\r\n"
#define SP " \t"
#define BACKLOG 8 /* client queue size */

#define SHA256_DIGEST_LENGTH 32
#define BLOCKCHAIN_DATA_MAX 1024

/**
 * struct block_info_s - define the metadata of a block_s
 *
 * @index: index of the block
 * @difficulty: difficulty of proof of work (hash leading zero)
 * @timestamp: UNIX time the block was created at
 * @nonce: salt used to hash the block
 * @prev_hash: hash of the previous block
 */
typedef struct block_info_s
{
	uint32_t index;
	uint32_t difficulty;
	uint64_t timestamp;
	uint64_t nonce;
	uint8_t prev_hash[SHA256_DIGEST_LENGTH];
} block_info_t;

/**
 * struct block_data_s - define the data of a block_s
 *
 * @buffer: data buffer of the block
 * @len: len of the data buffer
 */
typedef struct block_data_s
{
	/* data stays first to use this struct as an array */
	int8_t buffer[BLOCKCHAIN_DATA_MAX];
	uint32_t len;
} block_data_t;

/**
 * struct block_s - define a block in the blockchain
 *
 * @info: metadata of the block
 * @data: data of the block
 * @hash: hash of the block
 */
typedef struct block_s
{
	block_info_t info;
	block_data_t data;
	llist_t *transactions;
	uint8_t hash[SHA256_DIGEST_LENGTH];
} block_t;


/* socket */
int start_server(void);
int accept_messages(int sd);
int parse_request(int client_sd, char *buf);

/* deserialize */
block_t *deserialize_block(char *buffer);

#endif
