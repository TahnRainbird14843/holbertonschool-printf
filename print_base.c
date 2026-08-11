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
	char buffer[32];
	int i = 0, count = 0;
	
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		buffer[i++] = digits[n % base];
		n /= base;
	}

	while (i--)
	{
		write(1, &buffer[i], 1);
		count++;
	}

	return (count);
}
