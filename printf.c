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

	if (!str)
		exit(98);

	if (str[0] == '%' && str[1] == '\0')
		exit(98);

	va_start(args, str);

	memset(buffer, 0, 1024);

	while (str[i])
	{
		if (str[i] == '%')
		{
			if (j > 0)
			{
				write(1, buffer, j);
				count += j;
				memset(buffer, 0, j);
				j = 0;
			}

			i++;

			if (str[i] == '\0')
			{
				exit(98);
			}

			if (str[i] == '%')
			{
				write(1, "%", 1);
				count++;
				i++;
				continue;
			}

			func = get_print_func(str[i]);
			if (!func)
			{
				write(1, "%", 1);
				write(1, &str[i], 1);
				count += 2;
				i++; 
				continue;
			}

			count += func(args);
			memset(buffer, 0, j);
			j = 0;
			i++;
			continue;

		}
		else if (j == 1024)
		{
			write(1, buffer, j);
			count += j;
			memset(buffer, 0, j);
			j = 0;
		}
		else
		{
			buffer[j] = str[i];
			j++;
			i++;
		}
	}

	write(1, buffer, j);
	count += j;
	va_end(args);
	free(buffer);

	return (count);
}
