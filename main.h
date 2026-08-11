#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct print_func - identifier structure
 *
 * @ch: input identifier character
 * @f: associated print function
 */
typedef struct print_func
{
	char ch;
	int (*f)(va_list);
} print_func;

int _printf(const char *format, ...);
int print_int(va_list);
int print_char(va_list);
int print_str(va_list);
int print_unsigned(va_list);
int (*get_print_func(char ch))(va_list);
void throw_error(int n);
int power(int n, int i);
int print_oct(va_list);
int print_hex_low(va_list);
int print_hex_up(va_list);
int print_base(unsigned int n, int base, int up);

#endif
