/*
 * ==========================================================================
 *
 *       Filename:  ec_sign.c
 *
 *    Description:  signs a given set of bytes, using a given EC_KEY
 *
 *        Version:  1.0
 *        Created:  03/07/25 10:22:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Leveque 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "hblk_crypto.h"


uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen,
		sig_t *sig)
{
	if (!key || !msg || !sig)
		return (NULL);

	if (ECDSA_sign(0, msg, msglen, sig->sig, &(sig->len), (EC_KEY *)key) != 1)
		return (NULL);

	return (sig->sig);
}

