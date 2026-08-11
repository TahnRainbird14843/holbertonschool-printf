#include "main.h"
#include <stdarg.h>

/**
 * print_oct - prints unsigned int in octal
 * @args: lsit arguments
 *
 * Return: num of chars printed
 */

int print_oct(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	return print_base(n, 8, 0);
}

/**
 * print_hex_up - prints unsigned int in upper hex
 * @args: list of arguments
 *
 * Return: num of chars printed
 */

int print_hex_up(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	return print_base(n, 16, 1);
}

/**
 * print_hex_low - prints unsigned int in low hex
 * @args: list of arguments
 *
 * Return: num of chars printed
 */

int print_hex_low(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	return print_base(n, 16, 0);
}

/**
 * print_binary - prints unsigned int in binary
 * @args: list of arguments
 *
 * Return: num of chars printed
 */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	return print_base(n, 2, 0);
}
