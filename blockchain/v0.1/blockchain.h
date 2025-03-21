#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
/*
 * ==========================================================================
 *
 *       Filename:  blockchain.h
 *
 *    Description:  header file for the blockchain v0.1
 *
 *        Version:  1.0
 *        Created:  14.03.2025 08:58:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

/* local header files */
#include "../../crypto/hblk_crypto.h"
#include "provided/endianness.h"

/* local linked list library */
#include <llist.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

#define HBLK_MAGIC "HBLK"
#define VERSION "0.1"
#define BLOCKCHAIN_DATA_MAX 1024

#define GENESIS_INDEX 0
#define GENESIS_DIFFICULTY 0
#define GENESIS_TIMESTAMP 1537578000
#define GENESIS_NONCE 0
#define GENESIS_PREV_HASH 0
#define GENESIS_LEN 16
#define GENESIS_BUFFER "Holberton School"
#define GENESIS_HASH "\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf\x2a\x97\xd4\x8d\x0c\x8e\x00\x09\xc8\x17\xf2\xb1\xd3\xd7\xff\x2f\x04\x51\x58\x03"
/* hex of 'c52c26c8b5461639635d8edf2a97d48d0c8e0009c817f2b1d3d7ff2f04515803' */



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
	uint8_t hash[SHA256_DIGEST_LENGTH];
} block_t;


/**
 * struct blockchain_s - define a chain of block_s
 *
 * @chain: linked list of ptr to block_t
 */
typedef struct blockchain_s
{
	llist_t *chain;
} blockchain_t;


/* core functions */
blockchain_t *blockchain_create(void);
block_t *block_create(block_t const *prev,
		int8_t const *data, uint32_t data_len);
void block_destroy(block_t *block);
void blockchain_destroy(blockchain_t *blockchain);
uint8_t *block_hash(block_t const *block,
		uint8_t hash_buf[SHA256_DIGEST_LENGTH]);
int blockchain_serialize(blockchain_t const *blockchain, char const *path);
blockchain_t *blockchain_deserialize(char const *path);
llist_t *deserialize_blocks(int fd, uint32_t size, uint8_t endianness);
int block_is_valid(block_t const *block, block_t const *prev_block);

/* other functions */



#endif /* BLOCKCHAIN_H */
