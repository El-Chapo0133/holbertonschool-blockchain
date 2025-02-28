/*
 * ==========================================================================
 *
 *       Filename:  ec_create.c
 *
 *    Description:  computes the hash of a sequence of bytes
 *
 *        Version:  1.0
 *        Created:  28.02.2025 09:36:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "hblk_crypto.h"

EC_KEY *ec_create(void)
{
	EC_KEY *key;

	key = EC_KEY_new_by_curve_name(EC_CURVE);
	if (!key) /* uh oh */
		return (NULL);
	if (!EC_KEY_generate_key(key))
	{
		EC_KEY_free(key);
		return (NULL);
	}
	return (key);
}
