#include "main.h"

/**
 * power - get the power of n^i
 * @n: base
 * @i: exponent
 *
 * Return: n ^ i
 */
int power(int n, int i)
{
	if (i == 0)
		return (1);

	return (n * power(n, i - 1));
}

/**
 * print_int - prints signed integer
 * @args: list of arguments from _printf
 *
 * Return: num of char printed
 */

int print_int(va_list args)
{
	unsigned int n;
	int i;
	int j = 0;
	char *buffer = malloc(10);

	if (n < 0)
	{
		n = -va_arg(args, int);
		buffer[j] = '-';
		j++;
	}
	else
		n = va_arg(args, int);

	for (i = 9; i >= 0; i--)
	{
		if (n >= power(10, i) && i == 9)
		{
			buffer[j] = '0' + (n / power(10, i));
			j++;
		}
		else if (n >= power(10, i))
		{
			buffer[j] = '0' + ((n % power(10, i + 1)) / power(10, i));
			j++;
		}
	}

	write(1, buffer, j);
	free(buffer);

	return (j);
}

/**
 * print_char - print a char from va_list
 * @args: input va_list
 *
 * Return: 0 always
 */

int print_char(va_list args)
{
	char *buffer = malloc(1);

	buffer[0] = '\0' + va_arg(args, int);

	write(1, buffer, 1);
	free(buffer);

	return (1);
}

/**
 * print_str - print a string from va_list
 * @args: input va_list
 *
 * Return: 0 always
 */

int print_str(va_list args)
{
	char *str = va_arg(args, char *);
	char *buffer = malloc(1024);
	
	int count = 0;
	int i = 0;

	if (!str)
		str = "(null)";

	while (str[count])
	{
		if (i == 1023)
		{
			write(1, buffer, 1024);
			i = 0;
		}
		else
		{
			buffer[i] = str[count];
			i++;
			count++;
		}
	}

	write(1, buffer, i);
	free(buffer);

	return count;
}

/**
 * print_unsigned - prints unsigned int
 * @args: list of arguments
 *
 * Return: num of char printed
 */

int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	return print_base(n, 10, 0);
}
