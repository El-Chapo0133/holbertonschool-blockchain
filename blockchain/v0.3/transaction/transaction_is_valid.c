/*
 * ==========================================================================
 *
 *       Filename:  transaction_is_valid.c
 *
 *    Description:  checks whether a transaction is valid
 *
 *        Version:  1.0
 *        Created:  11.04.2025 10:24:19
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
 * input_match - checks if an unspent token matches an input token
 * @u_token: unspent token
 * @i_token: input token
 *
 * Return: 1 if it matches, 0 otherwise
 */
int input_match(unspent_tx_out_t *u_token, tx_in_t *i_token)
{
	if (memcmp(u_token->out.hash, i_token->tx_out_hash, 32))
		return (0);
	if (memcmp(u_token->tx_id, i_token->tx_id, 32))
		return (0);
	if (memcmp(u_token->block_hash, i_token->block_hash, 32))
		return (0);
	return (1);
}

/**
 * transaction_is_valid - checks if a transaction is valid
 * @transaction: transaction to check
 * @all_unspent: llist of all unspent transaction
 *
 * Return: 1 if valid, 0 if not
 */
int transaction_is_valid(transaction_t const *transaction, llist_t *all_unspent)
{
	tx_in_t *i_token;
	unspent_tx_out_t *u_token;
	int index, u, u_size;
	uint32_t a_in = 0, a_out = 0;
	EC_KEY *u_key;
	uint8_t t_hash[SHA256_DIGEST_LENGTH];

	transaction_hash(transaction, t_hash);
	if (memcmp(transaction->id, t_hash, 32) != 0)
		return (0);
	u_size = llist_size(all_unspent);
	for (index = 0; index < llist_size(transaction->inputs); index++)
	{
		i_token = llist_get_node_at(transaction->inputs, index);
		for (u = 0; u < u_size; u++)
		{
			u_token = llist_get_node_at(transaction->outputs, u);
			if (input_match(u_token, i_token))
				break;
		}
		if (u == u_size)
			return (0);
		u_key = ec_from_pub(u_token->out.pub);
		u = ec_verify(u_key, transaction->id, SHA256_DIGEST_LENGTH, &i_token->sig);
		EC_KEY_free(u_key);
		if (u == 0)
			return (0);
		a_in += u_token->out.amount;
	}

	for (index = 0; index < llist_size(transaction->outputs); index++)
		a_out += ((tx_out_t *)llist_get_node_at(transaction->outputs, index))->amount;

	if (a_in != a_out)
		return (0);
	return (1);
}
