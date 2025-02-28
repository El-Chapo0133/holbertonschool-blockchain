/*
 * ==========================================================================
 *
 *       Filename:  _print_hex_buffer.c
 *
 *    Description:  print a buffer in hex values
 *
 *        Version:  1.0
 *        Created:  24.02.2025 12:07:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

/**
 * _print_hex_buffer - Prints a buffer in its hexadecimal form
 *
 * @buf: Pointer to the buffer to be printed
 * @len: Number of bytes from @buf to be printed
 */
void _print_hex_buffer(uint8_t const *buf, size_t len)
{
	size_t i;

	for (i = 0; buf && i < len; i++)
		printf("%02x", buf[i]);
}
