/*
 * ==========================================================================
 *
 *       Filename:  coinbase_is_valid.c
 *
 *    Description:  checks whether a coinbase transaction is valid
 *
 *        Version:  1.0
 *        Created:  11.04.2025 11:52:47
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
 * is_all_zero - checks if a buffer is all 0
 * @buffer: buffer to check
 * @size: buffer size
 *
 * Return: 1 if all zero, 0 otherwise
 */
int is_all_zero(uint8_t *buffer, size_t size)
{
	return (!*buffer && !memcmp(buffer, buffer + 1, size - 1));
}

/**
 * coinbase_is_valid - checks if a coinbase transaction is valid
 * @coinbase: coinbase to check
 * @block_index: index of the Block the coinbase transaction will belong to
 */
int coinbase_is_valid(transaction_t const *coinbase,
		uint32_t block_index)
{
	uint8_t hash[SHA256_DIGEST_LENGTH];
	tx_in_t *txi;
	tx_out_t *txo;

	if (!coinbase)
		return (0);
	if (!transaction_hash(coinbase, hash) ||
		memcmp(coinbase->id, hash, SHA256_DIGEST_LENGTH))
		return (0);
	if (llist_size(coinbase->inputs) != 1 ||
		llist_size(coinbase->outputs) != 1)
		return (0);
	txi = llist_get_node_at(coinbase->inputs, 0);
	txo = llist_get_node_at(coinbase->outputs, 0);
	if (memcmp(txi->tx_out_has, &block_index, 4))
		return (0);
	if (!is_all_zero(txi->block_hash, sizeof(txi->block_hash)) ||
		!is_all_zero(txi->tx_id, sizeof(txi->tx_id)) ||
		!is_all_zero((uint8_t *)&txi->sig, sizeof(txi->sig)))
		return (0);
	if (txo->amount != COINBASE_AMOUNT)
		return (0);
	return (1);
}
