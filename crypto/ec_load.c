/*
 * ==========================================================================
 *
 *       Filename:  ec_load.c
 *
 *    Description:  loads an EC key pair from the disk
 *
 *        Version:  1.0
 *        Created:  03/07/25 10:05:19
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
 * load_public_key - load the public key from given file
 * @f: file to read the key from
 * @key: ptr to key to load to
 *
 * Return: 1 on success 0 on failure
 */
int load_public_key(FILE *f, EC_KEY **key)
{
	if (!f)
		return (0);
	if (!PEM_read_EC_PUBKEY(f, &key, NULL, NULL))
		return (0);
	return (1);
}

/**
 * load_private_key - load the private key from given file
 * @f: file to read the key from
 * @key: ptr to key to load to
 *
 * Return: 1 on success 0 on failure
 */
int load_private_key(FILE *f, EC_KEY **key)
{
	if (!f)
		return (0);
	if (!PEM_read_ECPrivateKey(f, &key, NULL, NULL))
		return (0);
	return (1);
}

/**
 * ec_load - loads an EC key pair from the disk
 * @folder: path to the folder which contains the key
 *
 * Return: ptr to EC_KEY, NULL otherwise
 */
EC_KEY *ec_load(char const *folder)
{
	FILE *f;
	char path[PATH_MAX_SIZE] = {0};
	EC_KEY *key;

	if (!folder)
		return (NULL);

	/* loads public key */
	sprintf(path, "%s/" PUB_FILENAME, folder);
	f = fopen(path, "r");
	if (!f || !load_public_key(f, &key))
	{
		fclose(f);
		EC_KEY_free(key);
		return (NULL);
	}
	fclose(f);

	/* loads private key */
	sprintf(path, "%s/" PRI_FILENAME, folder);
	f = fopen(path, "r");
	if (!f || !load_private_key(f, &key))
	{
		fclose(f);
		EC_KEY_free(key);
		return (NULL);
	}

	fclose(f);
	return (key);
}
