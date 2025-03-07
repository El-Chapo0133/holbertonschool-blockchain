/*
 * ==========================================================================
 *
 *       Filename:  ec_verify.c
 *
 *    Description:  verifies the signature of a given set of bytes
 *			using a given EC_KEY public key
 *
 *        Version:  1.0
 *        Created:  03/07/25 10:31:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Leveque 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "hblk_crypto.h"

/**
 * ec_verify - verify a signature of msg using the given key
 * @key: key to use
 * @msg: message to verify
 * @msglen: length of msg
 * @sig: signature to verify
 *
 * Return: 1 on success 0 on failure
 */
int ec_verify(EC_KEY const *key, uint8_t const *msg, size_t msglen,
		sig_t const *sig)
{
	if (!key || !msg || !sig)
		return (NULL);

	return (ECDSA_verify(0, msg, msglen, sig->sig, sig->len,
				(EC_KEY *)key) == 1);
}
