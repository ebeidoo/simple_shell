#include "main.h"

/**
 * _memcpy - copies memory block
 *			location up until a certain
 *              memory byte
 *
 * @dest: destination
 * @src: source
 * @n: until a certain memory byte.
 */
void _memcpy(void *dest, void *src, size_t n)
{
	size_t i;
	char *cdest = (char *)dest;
	char *csrc = (char *)src;

	for (i = 0; i < n; i++)
		cdest[i] = csrc[i];
}
