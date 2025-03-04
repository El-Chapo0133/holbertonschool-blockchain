/*
 * =====================================================================================
 *
 *       Filename:  ec_from_pub.c
 *
 *    Description:  creates an EC_KEY structure given a public key
 *
 *        Version:  1.0
 *        Created:  03/04/25 13:11:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Leveque 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * =====================================================================================
 */

#include "hblk_crypto.h"

/**
 * ec_from_pub - generates EC_KEY from pub key
 * @pub: buffer for the pub key
 *
 * Return: ptr EC_KEY or NULL
 */
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN])
{
	EC_KEY *key;
	EC_POINT *point;

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
