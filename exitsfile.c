#include "main.h"

/**
 * strncpy - copies a string
 * @dest: pointer to destination string to be copied to
 * @src: pointer to source string
 * @n: maximum number of characters to be copied
 *
 * Return: pointer to the resulting string
 */
char *strncpy(char *dest, const char *src, size_t n)
{
	char *ret = dest;
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (ret);
}

/**
 * strncat - concatenates two strings
 * @dest: pointer to the first string
 * @src: pointer to the second string
 * @n: maximum number of characters to be appended from src
 * Return: pointer to the resulting string
 */
char *strncat(char *dest, const char *src, size_t n)
{
	char *ret = dest;
	size_t dest_len = strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';

	return (ret);
}

/**
 * strchr - locates a character in a string
 * @s: pointer to the string to be searched
 * @c: character to look for
 * Return: pointer to the first occurrence of the character in the string
 * or NULL if the character is not found
 */
char *strchar(const char *s, char c)
{
	do {
		if (*s == c)
			return (char *)s;
	} while (*s++ != '\0');

	return (NULL);
}
