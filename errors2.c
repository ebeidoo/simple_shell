#include "main.h"

/**
 * err_atoi - converts a string to an integer
 * @str: the string to be converted
 * Return: the converted number if successful, -1 on error
 */
int err_atoi(char *str)
{
	int i;
	unsigned long int result = 0;

	if (*str == '+')
		str++;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return ((int)result);
}

/**
 * print_error - prints an error message
 * @info: a pointer to the parameter & return info struct
 * @estr: a string containing the specified error type
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - prints a decimal (integer) number (base 10)
 * @input: the integer to print
 * @fd: the file descriptor to write to
 * Return: the number of characters printed
 */
int print_d(int input, int fd)
{
	int (*_putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int abs_val, current;

	if (fd == STDERR_FILENO)
		_putchar = _eputchar;
	if (input < 0)
	{
		abs_val = -input;
		_putchar('-');
		count++;
	}
	else
		abs_val = input;
	current = abs_val;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (abs_val / i)
		{
			_putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	_putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converts a number to a string
 * @num: the number to convert
 * @base: the base to convert to
 * @flags: argument flags
 * Return: the converted string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *digits;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	digits = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = digits[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
