#include "main.h"

/**
 * throw_error - throws an error based on the input int
 * @n: input int
 */
void throw_error(int n)
{

	char *msg;
	
	
	if (n == 0)
		msg = "Incorrect identifier: try %d, %i, %c, %s, %u, %o, %x, %X\n";
	else if (n == 1)
		msg = "Argument type does not match identifier\n";
	else
		msg = "NULL argument where non-NULL argument was expected\n";

	write(1, msg, strlen(msg));
	exit(98);
}
