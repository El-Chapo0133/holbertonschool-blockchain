/*
 * ==========================================================================
 *
 *       Filename:  unspent_tx_out_create.c
 *
 *    Description:  allocates and initializes an unspent
 *			transaction output structure
 *
 *        Version:  1.0
 *        Created:  04.04.2025 11:22:28
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
 * unspent_tx_out_create - allocates and initializes an unspent
 * transaction output structure
 * @block_hash: ptr to block_t hash with transaction ref
 * @tx_id: hash of transaction
 * @out: ptr to transaction output
 *
 * Return: newly unspent_tx_out_t or NULL
 */
unspent_tx_out_t *unspent_tx_out_create(
	uint8_t block_hash[SHA256_DIGEST_LENGTH],
	uint8_t tx_id[SHA256_DIGEST_LENGTH], tx_out_t const *out)
{
	unspent_tx_out_t *utx = malloc(sizeof(unspent_tx_out_t));

	if (!utx)
		return (NULL);
	memcpy(utx->block_hash, block_hash, sizeof(utx->block_hash));
	memcpy(utx->tx_id, tx_id, sizeof(utx->tx_id));
	memcpy(&utx->out, out, sizeof(utx->out));
	return (utx);
}
