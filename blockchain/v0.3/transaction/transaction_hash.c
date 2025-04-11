/*
 * ==========================================================================
 *
 *       Filename:  transaction_hash.c
 *
 *    Description:  computes the ID (hash) of a transaction
 *
 *        Version:  1.0
 *        Created:  11.04.2025 09:01:27
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
 * transaction_hash - compute the ID of a transaction
 * @transaction: transaction to compute the ID of
 * @hash_buf: buffer in which to store the computed hash
 *
 * Return: ptr to hash buffer or NULL
 */
uint8_t *transaction_hash(transaction_t const *transaction,
		uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	int8_t *hash_target;
	int in_len, out_len, target_len, offset, index;
	tx_out_t *temp_out;
	tx_in_t *temp_in;

	in_len = llist_size(transaction->inputs);
	out_len = llist_size(transaction->outputs);
	target_len = in_len * 96 + out_len * 32;

	hash_target = malloc(target_len);
	if (!target_len)
		return (NULL);

	offset = 0;
	for (index = 0; index < in_len; index++)
	{
		/* doomed loop because i can't use ->next or ++ */
		temp_in = llist_get_node_at(transaction->inputs, index);
		memcpy(hash_target + offset, temp_in, 96);
		offset += 96;
	}
	for (index = 0; index < out_len; index++)
	{
		/* doomed loop because i can't use ->next or ++ */
		temp_out = llist_get_node_at(transaction->outputs, index);
		memcpy(hash_target + offset, temp_out->hash, 32);
		offset += 32;
	}

	sha256(hash_target, target_len, hash_buf);
	free(hash_target);

	return (hash_buf);
}
