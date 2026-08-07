#include "main.h"

/**
 * print_string - writes string
 * @s: string to print
 *
 * Return: number of characters printed
 */

int _printf(const char *str, ...)
{
	int count = 0;
	int i = 0;
	int j = 0;
	char *buffer = malloc(1024);
	int (*func)(va_list);
	va_list args;

	if (!buffer)
		return(-1);

	va_start(args, str);

	if (!str)
		throw_error(2);

	memset(buffer, 0, 1024);

	while (str[i])
	{
		if (str[i] == '%')
		{
			write(1, buffer, j);
			memset(buffer, 0, 1024);
			i++;
			func = get_print_func(str[i]);
			if (!func)
				throw_error(0);
			count += func(args);
			
			i++; 
			j = 0;
			continue;
		}
		else if (j == 1023)
		{
			write(1, buffer, j);
			memset(buffer, 0, 1024);
			j = 0;
		}
		else
		{
			buffer[j++] = str[i++];
			count++;
		}
	}

	write(1, buffer, j);
	va_end(args);
	free(buffer);

	return (count);
}
