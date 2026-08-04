#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

typdef struct print_func
{
	char *str;
	int (*f)(va_list);
} print_func;

int _printf(const char *format, ...);
int print_int(va_list);
int print_char(va_list);
int print_str(va_list);
int print_uint(va_list);
int (*f)(va_list) get_print_func(char *str);
int print_string(char *str);
int count_digits(unsigned int n);
void print_number(unsigned int n);


#endif
