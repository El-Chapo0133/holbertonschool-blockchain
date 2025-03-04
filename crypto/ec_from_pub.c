/*
 * ==========================================================================
 *
 *       Filename:  ec_from_pub.c
 *
 *    Description:  creates an EC_KEY structure given a public key
 *
 *        Version:  1.0
<<<<<<< HEAD
 *        Created:  28.02.2025 12:10:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
=======
 *        Created:  03/04/25 13:11:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Leveque 9601@holbertonstudents.com
>>>>>>> 1bcd48c0344b42b402175fc1bae8db53cbc8fdae
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

	if (!pub)
		return (NULL);
	/* create a key from the curve name */
	key = EC_KEY_new_by_curve_name(EC_CURVE);
	if (!key)
		return (NULL);

	/* create a point*/
	point = EC_POINT_new(EC_KEY_get0_group(key));
	if (!point)
	{
		EC_KEY_free(key);
		return (NULL);
	}

	/* creates an EC_KEY structure given a public key */
	if (!EC_POINT_oct2point(EC_KEY_get0_group(key),
		point, pub,
		EC_PUB_LEN, NULL)
		|| !EC_KEY_set_public_key(key, point))
	{
		EC_KEY_free(key);
		EC_POINT_free(point);
		return (NULL);
	}

	EC_POINT_free(point);
	return (key);
}
