/*
 * ==========================================================================
 *
 *       Filename:  ec_save.c
 *
 *    Description:  saves an existing EC key pair on the disk
 *
 *        Version:  1.0
 *        Created:  03/04/25 13:15:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Leveque 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "hblk_crypto.h"

int write_private_key(FILE *file, EC_KEY *key)
{
	if (!PEM_write_ECPrivateKey(file, key, NULL, NULL, 0, NULL, NULL))
	{
		fprintf(stderr, "Cannot write private key to file");
		fclose(file);
		return (0);
	}
	return (1);
}

int write_public_key(FILE *file, EC_KEY *key)
{
	if (!PEM_write_EC_PUBKEY(file, key))
	{
		fprintf(stderr, "Cannot write public key to file");
		fclose(file);
		return (0);
	}
	return (1);
}

int ec_save(EC_KEY *key, char const *folder)
{
	FILE *f; /* requires a FILE, can't use an fd */
	char path[PATH_MAX_SIZE] = {0};

	if (!key || !folder)
		return (0);

	/**
	 * permissions :
	 * S_IRWXU : Read Write and Execute to owner
	 * S_IRWXG : Read Write and Execute to owner's group
	 * S_IROTH : Read to others
	 * S_IXOTH : Execute to others
	 */
	mkdir(folder, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	/* write the private key */
	sprintf(path, "%s/" PRI_FILENAME, folder);
	f = fopen(path, "w");
	if (!f)
		return (0);
	if (!write_private_key(f, key))
		return (0);

	/* write the public key */
	sprintf(path, "%s/" PUB_FILENAME, folder);
	f = fopen(path, "w");
	if (!f)
		return (0);
	if (!write_public_key(f, key))
		return (0);

	fclose(f);
	return (1);
}
