#ifndef H_HBLK_CRYPTO
#define H_HBLK_CRYPTO
/*
 * ==========================================================================
 *
 *       Filename:  hblk_crypto.h
 *
 *    Description:  header file for the provided crypto lib
 *
 *        Version:  1.0
 *        Created:  24.02.2025 12:05:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>

#include <openssl/sha.h>
#include <openssl/ec.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <openssl/pem.h>

/* Maximum signature octet string length (using 256-bit curve) */
#define SIG_MAX_LEN 72
#define EC_CURVE NID_secp256k1
/* EC_KEY public key octet string length (using 256-bit curve) */
#define EC_PUB_LEN 65
#define PRI_FILENAME "key.pem"
#define PUB_FILENAME "key_pub.pem"
#define PATH_MAX_SIZE 256 /* 256 for ext4, 4096 otherwise */

/**
 * struct signature_s - EC signaure struct
 * @sig: signature buffer
 * @len: sig len
 */
typedef struct signature_s
{
	uint8_t sig[SIG_MAX_LEN];
	uint8_t len;
} signature_t;

uint8_t *sha256(int8_t const *s, size_t len,
		uint8_t digest[SHA256_DIGEST_LENGTH]); /* length:32 */
/*  Task 1 */
EC_KEY *ec_create(void);
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN]);
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN]);
int ec_save(EC_KEY *key, char const *folder);
EC_KEY *ec_load(char const *folder);
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg,
		size_t msglen, signature_t *sig);
int ec_verify(EC_KEY const *key, uint8_t const *msg,
		size_t msglen, signature_t const *sig);

#endif /* H_HBLK_CRYPTO */
