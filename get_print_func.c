#include "main.h"

/**
 * get_print_func - get the correct function based on type
 * @str: input string
 *
 * Return: pointer to the correct print function
 */
int (*get_print_func(char ch))(va_list)
{
        print_func funcs[4] = {
                {'d', print_int},
                //{'i', print_uint},
                {'c', print_char},
                {'s', print_str},
                {'\0', NULL}
        };
        int i = 0;

        while (funcs->ch != '\0')
        {
                if (funcs->ch = ch)
                        return (funcs->f);
        }

        return (NULL);
}
