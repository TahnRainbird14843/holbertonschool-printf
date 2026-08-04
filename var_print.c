#include "main.h"

/**
 * print_number - prints unsigned int
 * @n: num to print
 *
 */

void print_number(unsigned int n)
{
	char c;

	if (n / 10)
		print_number(n / 10);

	c = (n % 10) + '0';
	write(1, &c, 1);
}

/**
 * count_digits - counts digits in unsigned int
 * @n: number to eval
 *
 * Return: divide num by 10 rep until 0
 * each div removes one digit
 */

int count_digits(unsigned int n)
{
	int count = 0;

	do {
		count++;
		n /= 10;
	} while (n != 0);

	return count;
}

/**
 * print_int - prints signed integer
 * @args: list of arguments from _printf
 *
 * Return: num of char printed
 */

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
	char c = (char) va_arg(args, int);

	write(1, &c, 1);

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
	
	int count = 0;

	if (!str)
		str = "(nil)";

	while (str[count])
		write(1, &str[count], 1), count++;

	return count;
}
