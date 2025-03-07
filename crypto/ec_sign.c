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

/**
 * ec_sign - signs a given set of bytes with the given EC_KEY
 * @key: key to use to sign
 * @msg: message to sign
 * @msglen: msg length
 * @sig: ptr to sig_t to store the signature
 *
 * Return: ptr to sig_t or NULL
 */
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen,
		sig_t *sig)
{
	unsigned int sig_len;

	if (!key || !msg || !sig)
		return (NULL);

	sig_len = SIG_MAX_LEN;
	if (ECDSA_sign(0, msg, msglen, sig->sig, &sig_len,
				(EC_KEY *)key) != 1)
		return (NULL);
	/* update needed to verify the generated signature */
	sig->len = sig_len;

	return (sig->sig);
}

