/*
 * ==========================================================================
 *
 *       Filename:  ec_from_pub.c
 *
 *    Description:  creates an EC_KEY structure given a public key
 *
 *        Version:  1.0
 *        Created:  28.02.2025 12:10:51
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
 * ec_from_pub - create am EC_KEY struct from public key
 * @pub: buffer of the public key
 *
 * Return: ptr to EC_KEY or NULL
 */
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN])
{
	EC_KEY *key;
	const EC_POINT *point = NULL;
	const EC_GROUP *group = NULL;

	if (!pub) /* uh oh */
		return (NULL);

	/* first create a new key with the correct curve */
	key = EC_KEY_new_by_curve_name(EC_CURVE); /* see: NID_secp256k1 */
	if (!key)
		return (NULL);

	group = EC_KEY_get0_group(key);
	if (!group)
	{
		EC_KEY_free(key);
		return (NULL);
	}
	point = EC_POINT_new(group);
	if (!point)
	{
		EC_GROUP_free(group);
		EC_KEY_free(key);
		return (NULL);
	}

	EC_POINT_free(point);
	EC_GROUP_free(group);
	return (key);
}
