#include "main.h"

/**
 * int_log - implementation of an integer logarithm
 * @b: base
 * @n: input
 *
 * Return: integer log of n in base b
 */
unsigned int int_log(unsigned int b, unsigned int n)
{
	if (n == 0)
		return (1);

	if (n / b == 0)
		return (1);
	
	return (int_log(b, n / b) + 1);
}

/**
 * power - get the power of n^i
 * @n: base
 * @i: exponent
 *
 * Return: n ^ i
 */
unsigned int power(unsigned int n, int i)
{
	if (i == 0)
		return (1);

	return (n * power(n, i - 1));
}
