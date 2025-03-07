/*
 * ==========================================================================
 *
 *       Filename:  ec_create.c
 *
 *    Description:  creates a new EC key pair
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

/**
 * ec_create - creates a new EC key pair
 *
 * Return: key or NULL
 */
EC_KEY *ec_create(void)
{
	EC_KEY *key;

	/* create a _struct_ based on EC_CURVE (elliptic) */
	key = EC_KEY_new_by_curve_name(EC_CURVE); /* see: NID_secp256k1 */
	if (!key) /* uh oh */
	{
		fprintf(stderr, "Failure : generating EC_KEY");
		return (NULL);
	}
	/* generate the actual key, return 1 on success */
	if (!EC_KEY_generate_key(key))
	{
		fprintf(stderr, "Failure : generating EC_KEY");
		/* on failure: free the key */
		EC_KEY_free(key);
		return (NULL);
	}
	return (key);
}
