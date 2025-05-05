#ifndef H_CLI
#define H_CLI
/*
 * ==========================================================================
 *
 *       Filename:  cli.h
 *
 *    Description:  cli header file
 *
 *        Version:  1.0
 *        Created:  04/29/25 09:58:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Leveque (), 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include <stdio.h>
#include <string.h>

#include "../blockchain/v0.3/blockchain.h"
#include "llist.h"


/**
 * struct command_s - struct to regroup a command and it's args
 * @cmd: command to execute (1 word no space)
 * @args1: arg 1 (1 word no space)
 * @args2: arg 2 (1 word no space)
 */
typedef struct command_s
{
	char *cmd;
	char *args1;
	char *args2;
} command_t;

/**
 * struct blockchain_state_s - current state of the blockchain
 * @blockchain: the blockchain
 * @block: active block
 * @wallet: current wallet
 * @tx_pool: current transaction pool
 */
typedef struct blockchain_state_s
{
	blockchain **blockchain;
	block_t **block;
	EC_KEY **wallet;
	llist_t *tx_pool;
} blockchain_state_t;


/**
 * struct gball_s: struct to match a cmd to a function
 * @cmd: cmd to match
 * @f: function to execute that has been matched
 */
typedef struct gball_s
{
	char *cmd;
	int (*f)(blockchain_t **, block_t **, EC_KEY **, char *, char *);
} gumball_t;


/* gumball functions */
int (*gumball(char *cmd))(blockchain_t **, block_t **, EC_KEY **, char *, char *);

/* core functions */
int bi_help(blockchain_state_t *, char *, char *);
int bi_wallet_load(blockchain_state_t *, char *, char *);
int bi_wallet_save(blockchain_state_t *, char *, char *);
int bi_send(blockchain_state_t *, char *, char *);
int bi_mine(blockchain_state_t *, char *, char *);
int bi_info(blockchain_state_t *, char *, char *);
int bi_load(blockchain_state_t *, char *, char *);
int bi_save(blockchain_state_t *, char *, char *);


#endif 
