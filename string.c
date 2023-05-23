#include "main.h"

/**
* custom_strlen - returns the length of a string
* @str: the string whose length to calculate
*
* Return: the length of the string
*/
int custom_strlen(char *str)
{
int length = 0;

if (!str)
return (0);

while (*str != '\0')
{
length++;
str++;
}
return (length);
}


#include "shell.h"

/**
*custom_strcmp - Compare two strings lexicographically
* @str1: The first string to compare
* @str2: The second string to compare
*
* Return: Integer less than, equal to,
*			or greater than zero if str1 is
*         found to be less than, equal to,
*		  or greater than str2, respectively
*/
int custom_strcmp(char *str1, char *str2)
{
while (*str1 && (*str1 == *str2))
{
str1++;
str2++;
}

return (*str1 - *str2);
}


#include "shell.h"

/**
* starts_with - Check if a string starts with another string
* @str: The string to search within
* @prefix: The prefix string to search for
*
* Return: Pointer to the character in str where prefix starts,
*         or NULL if str does not start with prefix
*/
char *starts_with(const char *str, const char *prefix)
{
while (*prefix)
{
if (*prefix != *str)
return (NULL);

prefix++;
str++;
}

return ((char *)str);
}


#include "shell.h"

/**
* custom_strcat - Concatenate two strings
* @dest: The destination string to which the source string will be appended
* @src: The source string to be appended to the destination string
*
* Return: Pointer to the resulting concatenated string
*/
char *custom_strcat(char *dest, char *src)
{
char *result = dest;

while (*dest)
dest++;

while (*src)
*dest++ = *src++;

*dest = *src;

return (result);
}


#include "shell.h"

/**
* custom_strcpy - Copy a string
* @dest: The destination buffer to copy the string to
* @src: The source string to be copied
*
* Return: Pointer to the destination buffer
*/
char *custom_strcpy(char *dest, char *src)
{
int index = 0;

if (dest == src || src == NULL)
return (dest);

while (src[index])
{
dest[index] = src[index];
index++;
}

dest[index] = '\0';

return (dest);
}



#include "shell.h"

/**
* custom_strdup - Duplicate a string
* @str: The string to be duplicated
*
* Return: Pointer to the newly allocated duplicated string,
*         or NULL if str is NULL or if memory allocation fails
*/
char *custom_strdup(const char *str)
{
int length = 0;
char *duplicate;

if (str == NULL)
return (NULL);

while (*str++)
length++;

duplicate = malloc(sizeof(char) * (length + 1));

if (!duplicate)
return (NULL);

for (length++; length--;)
duplicate[length] = *--str;

return (duplicate);
}


#include "shell.h"

/**
* custom_puts - Print a string
* @str: The string to be printed
*
* Return: None
*/
void custom_puts(char *str)
{
	int index = 0;

	if (str == NULL)
		return;

	while (str[index] != '\0')
	{
		custom_putchar(str[index]);
		index++;
	}
}


#include "shell.h"

/**
* custom_putchar - Write a character to the standard output
* @c: The character to be written
*
* Return: On success, returns 1. On error, returns -1.
*/
int custom_putchar(char c)
{
	static int index;
	static char buffer[WRITE_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || index >= WRITE_BUFFER_SIZE)
	{
		write(1, buffer, index);
		index = 0;
	}
	if (c != BUFFER_FLUSH)
		buffer[index++] = c;
	return (1);
}
