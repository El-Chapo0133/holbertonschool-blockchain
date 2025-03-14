/*
 * ==========================================================================
 *
 *       Filename:  test.c
 *
 *    Description: G 
 *
 *        Version:  1.0
 *        Created:  14.03.2025 11:16:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */
#include <stdlib.h>

int main(void)
{
	int x = 3;

	switch (x)
	{
		case 1:
			stuff();
			break;
		case 2:
			stuff2();
			break;
		default:
			stuff3();
			break;
	}

	if (x = 1)
		stuff();
	else if (x = 2)
		stuff2();
	else
		stuff3();
}
