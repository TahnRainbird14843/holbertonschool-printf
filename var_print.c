#include "main.h"

/**
 * print_int - print an integer from va_list
 * @args: input va_list
 *
 * Return: 0 always
 */

void print_number(unsigned int n)
{
	char c;

	if (n / 10)
		print_number(n / 10);

	c = (n % 10) + '0';
	write(1, &c, 1);
}

int count_digits(unsigned int n)
{
	int count = 0;

	do {
		count++;
		n /= 10;
	} while (n != 0);

	return count;
}

int print_int(va_list args)
{
	int n = va_arg(args, int);
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	print_number(num);
	count += count_digits(num);
	
	return count;
}

/**
 * print_char - print a char from va_list
 * @args: input va_list
 *
 * Return: 0 always
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (0);
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

	return (0);
}
