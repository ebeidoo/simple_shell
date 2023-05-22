#include "main.h"

/**
 * is_file - checks if path is a file
 * @path: the path to check
 * Return: 1 if path is a file, 0 otherwise
 */
int is_file(char *path)
{
	struct stat st;

	if (stat(path, &st) == 0)
		return S_ISREG(st.st_mode);

	return 0;
}

/**
 * str_concat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 * Return: pointer to concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	char *result = malloc(len1 + len2 + 1);

	if (result == NULL)
		return NULL;

	strcpy(result, s1);
	strcat(result, s2);
	return result;
}

/**
 * print_array - prints an array of strings
 * @arr: the array of strings
 * @size: the size of the array
 * Return: void
 */
void print_array(char **arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%s\n", arr[i]);
}

/**
 * get_env - gets the value of an environment variable
 * @s: the string of the environment variable
 * Return: integer value of environment variable, 0 if not found
 */

int get_env(char *s)
{
	int q, sign = 1, flag = 0, output = 0;
	unsigned int result = 0;

	for (q = 0; s[q] != '\0' && flag != 2; q++)
	{
		if (s[q] == '-')
			sign *= -1;

		if (s[q] >= '0' && s[q] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[q] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;
	return output;
}
