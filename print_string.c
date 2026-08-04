#include "main.h"

/**
 * print_string - writes string
 * @s: string to print
 *
 * Return: number of characters printed
 */

int print_string(char *str)
{
	int count = 0;

	if (!str)
		str = "(null)";

	while (str[count])
		write(1, &str[count], 1), count++;

	return (count);
}
