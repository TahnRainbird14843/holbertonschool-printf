#include "main.h"

/**
 * print_int - print an integer from va_list
 * @args: input va_list
 *
 * Return: 0 always
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);

	return (0);
}

/**
 * print_uint - print an unsigned int from va_list
 * @args: input va_list
 *
 * Return: 0 always
 */
int print_uint(va_list arg)
{
	unsigned int n = va_arg(args, unsigned int);

	return (0);
}

/**
 * print_char - print a char from va_list
 * @args: input va_list
 *
 * Return: 0 always
 */
int print_char(va_list args)
{
	char c = va_arg(args, char);

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
	char *str = va_arg(args, char);

	return (0);
}


/**
 * get_print_func - get the correct function based on type
 * @str: input string
 *
 * Return: pointer to the correct print function
 */
int (*f)(va_list) get_print_func(char *str)
{
	print_func *funcs = {
		{"d", print_int},
		{"i", print_uint},
		{"c", print_char},
		{"s", print_str},
		{NULL, NULL}
	};
	int i = 0;

	while (funcs.str != NULL)
	{
		if (*(funcs.str) = *str)
			return (funcs.f);
	}

	return (NULL);
}
