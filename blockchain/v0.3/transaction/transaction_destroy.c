/*
 * ==========================================================================
 *
 *       Filename:  transaction_destroy.c
 *
 *    Description:  deallocates a transaction structure
 *
 *        Version:  1.0
 *        Created:  11.04.2025 12:41:33
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
 * transaction_destroy - deallocates a transaction struct
 * @transaction: transaction to deallocate
 */
void transaction_destroy(transaction_t *transaction)
{
	if (!transaction)
		return;
	llist_destroy(transaction->inputs, 1, free);
	llist_destroy(transaction->outputs, 1, free);
	free(transaction);
}
