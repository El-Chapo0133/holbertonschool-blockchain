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
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>

#include <llist.h>

#include "../crypto/hblk_crypto.h"
#include "../blockchain/v0.3/blockchain.h"
#include "../blockchain/v0.3/provided/provided.h"
#include "../blockchain/v0.3/transaction/transaction.h"

#define BLANK " \t\n"
#define PROMPT "> "

/**
 * struct state_s - CLI state structure
 *
 * @status: status of the most recently executed command
 * @argc: command argument count
 * @argv: command argument vector
 * @line: command line buffer
 * @linesz: size of @line
 * @wallet: wallet
 * @blockchain: blockchain
 * @tx_pool: transaction pool
 */
typedef struct state_s
{
        int status;
        int argc;
        char **argv;
        char *line;
        size_t linesz;
        EC_KEY *wallet;
        blockchain_t *blockchain;
        llist_t *tx_pool;
} state_t;

/**
 * struct gball_s: struct to match a cmd to a function
 * @cmd: cmd to match
 * @f: function to execute that has been matched
 */
typedef struct gball_s
{
	char *cmd;
	int (*f)(state_t *);
} gumball_t;


/* gumball functions */
int (*gumball(char *cmd))(state_t *);

/* CORE functions */
int cli_exit(state_t *state);
int cli_help(state_t *state);
int cli_info(state_t *state);
int cli_load(state_t *state);
int cli_mine(state_t *state);
int cli_save(state_t *state);
int cli_send(state_t *state);
int cli_wallet_load(state_t *state);
int cli_wallet_save(state_t *state);
void state_init(state_t *state);
void state_destroy(state_t *state);

#endif /* CLI_H */
 