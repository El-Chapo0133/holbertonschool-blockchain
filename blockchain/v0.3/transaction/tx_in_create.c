/*
 * ==========================================================================
 *
 *       Filename:  tx_in_create.c
 *
 *    Description:  allocates and initializes a transaction input structure
 *
 *        Version:  1.0
 *        Created:  11.04.2025 08:48:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "transaction.h"

/*
 * tx_in_create - allocate a new tx_in_t struct
 * @unspent: ptr to unspent struct
 *
 * Return: newly created struct or NULL
 */
tx_in_t *tx_in_create(unspent_tx_out_t const *unspent)
{
	tx_in_t *txi = malloc(sizeof(tx_in_t));

	if (!unspent || !txi)
		return (NULL);

	memcpy(txi->block_hash, unspent->block_hash, SHA256_DIGEST_LENGTH);
	memcpy(txi->tx_id, unspent->tx_id, sizeof(unspent->tx_id));
	memcpy(txi->tx_out_hash, unspent->out.hash, SHA256_DIGEST_LENGTH);
	return (txi);
}

