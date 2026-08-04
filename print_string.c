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
	int (*func)(va_list);
	va_list args;

	va_start(args, str);

	if (!str)
		throw_error(2);

	while (str[i])
	{
		if (str[i] == '%')
		{
			func = get_print_func(str[i + 1]);
			if (func == NULL)
				throw_error(0);
			count += func(args);
			i = i + 2;
		}
		else
			write(1, &str[i], 1), i++, count++;
	}

	va_end(args);

	return (count);
}
