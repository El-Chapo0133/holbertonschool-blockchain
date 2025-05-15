/*
 * ==========================================================================
 *
 *       Filename:  display_block.c
 *
 *    Description:  display blocks into stdout
 *
 *        Version:  1.0
 *        Created:  09.05.2025 07:46:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "cli_visual.h"

static int count = 0;


void print_x_spaces(int x)
{
        int index;

        for (index = 0; index < x; index++)
        {
                fprintf(stdout, " ");
        }
}


void print_hex_sha256(uint8_t *buffer)
{
        size_t index;

        for (index = 0; index < SHA256_DIGEST_LENGTH; index++)
        {
                fprintf(stdout, "%02x", buffer[index]);
        }
}

void display_genesis_block(void)
{
	fprintf(stdout, "+----------------------------------------------------------------------+\n");
	fprintf(stdout, "| NEW BLOCK %d                                                          |\n", count++);
	fprintf(stdout, "|----------------------------------------------------------------------|\n");
	fprintf(stdout, "| Timestamp: 1537578000                                                |\n");
	fprintf(stdout, "| Difficulty: 0                                                        |\n");
	fprintf(stdout, "| Nonce: 0                                                             |\n");
	fprintf(stdout, "| Previous hash:                                                       |\n");
	fprintf(stdout, "| 0                                                                    |\n");
	fprintf(stdout, "| Current hash:                                                        |\n");
	fprintf(stdout, "| c52c26c8b5461639635d8edf2a97d48d0c8e0009c817f2b1d3d7ff2f04515803     |\n");
	/*
        fprintf(stdout, "|----------------------------------------------------------------------|\n");
	fprintf(stdout, "| Transactions:                                                        |\n");
	fprintf(stdout, "| +------------------------------------------------------------------+ |\n");
	fprintf(stdout, "| | Transactions hash:                                               | |\n");
	fprintf(stdout, "| | 0                                                                | |\n");
	fprintf(stdout, "| |------------------------------------------------------------------| |\n");
	fprintf(stdout, "| | Inputs:                                                          | |\n");
	fprintf(stdout, "| |------------------------------------------------------------------| |\n");
	fprintf(stdout, "| | Outputs:                                                         | |\n");
	fprintf(stdout, "| +------------------------------------------------------------------+ |\n");
        */
	fprintf(stdout, "+----------------------------------------------------------------------+\n");
}

void display_block(block_t *block)
{
        unsigned int spaces_to_print = log10(count);


	fprintf(stdout, "+----------------------------------------------------------------------+\n");
	fprintf(stdout, "| NEW BLOCK %d                                                  ", count++);
        print_x_spaces(abs(8 - (int)spaces_to_print));
        fprintf(stdout, "|\n");
	fprintf(stdout, "|----------------------------------------------------------------------|\n");
	fprintf(stdout, "| Timestamp: %ld                                                |\n", block->info.timestamp);
	fprintf(stdout, "| Difficulty: %d                                                        |\n", block->info.difficulty);
	fprintf(stdout, "| Nonce: %ld                                                             |\n", block->info.nonce);
	fprintf(stdout, "| Previous hash:                                                       |\n");
	fprintf(stdout, "| ");
        print_hex_sha256(block->info.prev_hash);
        fprintf(stdout, "     |\n");
	fprintf(stdout, "| Current hash:                                                        |\n");
	fprintf(stdout, "| ");
        print_hex_sha256(block->hash);
        fprintf(stdout, "     |\n");
	/*
        fprintf(stdout, "|----------------------------------------------------------------------|\n");
	fprintf(stdout, "| Transactions:                                                        |\n");
	fprintf(stdout, "| +------------------------------------------------------------------+ |\n");
	fprintf(stdout, "| | Transactions hash:                                               | |\n");
	fprintf(stdout, "| | 0                                                                | |\n");
	fprintf(stdout, "| |------------------------------------------------------------------| |\n");
	fprintf(stdout, "| | Inputs:                                                          | |\n");
	fprintf(stdout, "| |------------------------------------------------------------------| |\n");
	fprintf(stdout, "| | Outputs:                                                         | |\n");
	fprintf(stdout, "| +------------------------------------------------------------------+ |\n");
	*/
        fprintf(stdout, "+----------------------------------------------------------------------+\n");
}
