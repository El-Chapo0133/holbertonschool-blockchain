/*
 * ==========================================================================
 *
 *       Filename:  coinbase_create.c
 *
 *    Description:  creates a coinbase transaction
 *
 *        Version:  1.0
 *        Created:  11.04.2025 11:20:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "transaction.h"

/**
 * free_transaction_resources - program that frees allocated
 * resources for a coinbase transaction
 *
 * @coinbase: the coinbase transaction to free
 * @input: the transaction input to free
 * @output: the transaction output to free
 *
 * Return: nothing (void)
 */

void free_transaction_resources(transaction_t *coinbase, tx_in_t *input,
				tx_out_t *output)
{
	if (output)
		free(output);

	if (input)
		free(input);

	if (coinbase)
	{
		if (coinbase->inputs)
			llist_destroy(coinbase->inputs, 1, NULL);

		if (coinbase->outputs)
			llist_destroy(coinbase->outputs, 1, NULL);

		free(coinbase);
	}
}



/**
 * coinbase_create - program that creates a coinbase transaction
 *
 * this function generates a new coinbase transaction, which is a special
 * type of transaction that miners include in a block to collect the block
 * reward and transaction fees;
 * it contains a single input and a single output;
 * the input is not linked to a previous transaction but is instead filled
 * with zeros and the block index;
 * the output contains the COINBASE_AMOUNT, which is credited to the miner's
 * address
 *
 * @receiver: the EC_KEY containing the public key of the miner who will
 *            receive the coinbase transaction
 * @block_index: the index of the block to which this coinbase transaction
 *               will be added
 *
 * Return: a pointer to the created coinbase transaction upon success,
 *         or NULL upon failure
 */

transaction_t *coinbase_create(EC_KEY const *receiver, uint32_t block_index)
{
	transaction_t *coinbase = malloc(sizeof(transaction_t));
	tx_in_t *input = malloc(sizeof(tx_in_t));
	tx_out_t *output;
	uint8_t pub[EC_PUB_LEN];
	int addInputResult, addOutputResult;

	if (!coinbase || !input || !ec_to_pub(receiver, pub))
	{
		free_transaction_resources(coinbase, input, NULL);
		return (NULL);
	}

	coinbase->inputs = llist_create(MT_SUPPORT_FALSE);
	coinbase->outputs = llist_create(MT_SUPPORT_FALSE);
	output = tx_out_create(COINBASE_AMOUNT, pub);

	if (!coinbase->inputs || !coinbase->outputs || !output)
	{
		free_transaction_resources(coinbase, input, output);
		return (NULL);
	}

	memset(input, 0, sizeof(tx_in_t));
	memcpy(input->tx_out_hash, &block_index, sizeof(block_index));

	addInputResult = llist_add_node(coinbase->inputs, input, ADD_NODE_FRONT);
	addOutputResult = llist_add_node(coinbase->outputs, output, ADD_NODE_FRONT);

	if (addInputResult == -1 || addOutputResult == -1 ||
	!transaction_hash(coinbase, coinbase->id))
	{
		free_transaction_resources(coinbase, input, output);
		return (NULL);
	}

	return (coinbase);
}