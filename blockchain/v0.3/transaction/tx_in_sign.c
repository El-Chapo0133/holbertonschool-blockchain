/*
 * ==========================================================================
 *
 *       Filename:  tx_in_sign.c
 *
 *    Description:  signs a transaction input
 *
 *        Version:  1.0
 *        Created:  11.04.2025 09:22:59
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
 * tx_in_sign - signs a transaction input
 * @in: ptr to transactiuon input
 * @tx_id: contains ID of the transaction
 * @sender: contains private key or the receiver
 * @all_unspent: list of all unspent transaction outputs
 *
 * Return: ptr to sig struct or NULL
 */
sig_t *tx_in_sign(tx_in_t *in, uint8_t const tx_id[SHA256_DIGEST_LENGTH],
		EC_KEY const *sender, llist_t *all_unspent)
{
	int unspent_len, index;
	unspent_tx_out_t *temp;
	llist_t *all_unspent;
	int8_t pubkey[EC_PUB_LEN];

	unspent_len = llist_size(all_unspent);
	for (index = 0; index < unspent_len; index++)
	{
		temp = llist_get_node_at(all_unspent, index);
		if (memcmp(in->tx_out_hash, temp->out.hash, 32) == 32)
			break;
	}

	if (index == unspent_len)
		return (NULL);
	ec_to_pub(sender, pubkey);

	if (memcmp(pubkey, temp->out.pub, EC_PUB_KEY) != 0)
		return (NULL);
	ec_sign(sender, tx_id, 32, &in->sig);
	return (&in->sig);
}
