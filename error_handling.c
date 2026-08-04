#include "main.h"

/**
 * throw_error - throws an error based on the input int
 * @n: input int
 */
void throw_error(int n)
{
	if (n == 0)
	{
		write(1, "Incorrent identifier: try %d, %i, %c, or %s\n", 44);
		exit(98);
	}

	if (n == 1)
	{
		write(1, "Argument type does not match identifier\n", 40);
		exit(98);
	}
	
	if (n == 2)
	{
		write(1, "NULL argument where non-NULL argument was expected\n", 51);
		exit(98);
	}
}
