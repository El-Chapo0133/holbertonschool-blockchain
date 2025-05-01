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


#include "llist.h"


typedef struct command_s
{
	char *cmd;
	char *args1;
	char *args2;
} command_t;



typedef struct gball_s
{
	char *cmd;
	int (*f)(blockchain_t **, block_t **, EC_KEY **, char *, char *);
} gumball_t;


/* gumball functions */
int (*gumball(char *cmd))(blockchain_t **, block_t **, EC_KEY **, char *, char *);




#endif 
