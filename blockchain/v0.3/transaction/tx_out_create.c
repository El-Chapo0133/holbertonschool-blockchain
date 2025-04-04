/*
 * ==========================================================================
 *
 *       Filename:  tx_out_create.c
 *
 *    Description:  allocates and initializes a transaction output structure
 *
 *        Version:  1.0
 *        Created:  04.04.2025 08:57:24
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
 * tx_out_create - allocates and initializes a transaction output structure
 * @amount: amount of the transaction
 * @pub: public key of the receiver
 *
 * Return: newly struct or NULL
 */
tx_out_t *tx_out_create(uint32_t amount, uint8_t const pub[EC_PUB_LEN])
{
	tx_out_t *transaction = malloc(sizeof(tx_out_t));

	if (!transaction)
		return (NULL);
	transaction->amount = amount;
	memcpy(transaction->pub, pub, EC_PUB_LEN);

	if (!sha256((int8_t const *)transaction,
			sizeof(transaction->amount) + EC_PUB_LEN,
			transaction->hash))
	{
		free(transaction);
		return (NULL);
	}
	return (transaction);
}
