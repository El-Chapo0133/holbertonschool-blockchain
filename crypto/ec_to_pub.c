/*
 * ==========================================================================
 *
 *       Filename:  ec_to_pub.c
 *
 *    Description:  extracts the public key from an EC_KEY opaque structure
 *
 *        Version:  1.0
 *        Created:  28.02.2025 10:42:02
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
 * ec_to_pub - extract the public key from EC_KEY struct
 * @key: ptr to EC_KEY struct
 * @pub: buffer to store the key
 *
 * Return: ptr to pub or NULL
 */
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
	const EC_GROUP *group = NULL;
	const EC_POINT *point = NULL;

	if (!key || !pub)
		return (NULL);

	/* get the group by the given key */
	group = EC_KEY_get0_group(key);
	/* get the public key point by the given key */
	point = EC_KEY_get0_public_key(key);
	/* convert the public key in octact into pub */
	if (!EC_POINT_point2oct(group, point,
			POINT_CONVERSION_UNCOMPRESSED,
			pub, EC_PUB_LEN, NULL))
		return (NULL);
	return (pub);
}
