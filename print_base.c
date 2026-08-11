#include "main.h"

/**
 * print_base - prints unsigned int any base
 * @n: num to print
 * @base: base convert
 *
 * return: num of char printed
 */

int print_base(unsigned int n, int base, int up)
{
	char *digits = up ? "0123456789ABCDEF" : "0123456789abcdef";
	unsigned int len = int_log(base, n);
	char *buffer = malloc(len + 1);
	int i = len - 1;

	while (i >= 0)
	{
		buffer[i] = digits[n % base];
		n = n / base;
		i--;
	}

	write(1, buffer, len);
	free(buffer);

	return (len);
}
