#include "main.h"
/**
 * print_all - chose the right function
 * @ch: character
 * Return: 0
 */
int (*print_all(const char ch))(va_list)
{
    int kk=0;

    list_t printf[] = {
        {'c', print_character},
        {'s', print_string},
        {'d', print_integer},
        {'i', print_integer},
        {'\0', NULL}};

    while (printf[kk].specifiers != '\0')
    {
        if (ch == (printf[kk].specifiers))
        {
            return (printf[kk].f);
        }
        kk++;
    }
    return (0);
}

/**
 * _printf - printf function that print character, integer and string
 * @format: variable
 * Return: -1,j,0
 */
int _printf(const char *format, ...)
{
    va_list ap;
    unsigned int i = 0, j = 0;

    if (format==NULL)
        return (-1);

    va_start(ap, format);
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == '\0')
                return (-1);

            else if (format[i + 1] == '%')
            {
                _putchar('%');
                j++;
                i++;
            }
            else if (print_all(format[i + 1]) != NULL)
            {
                j += (print_all(format[i + 1]))(ap);
                i++;
            }
            else
			{
				_putchar(format[i]);
				j++;
			}
        }
        else
        {
            _putchar(format[i]);
            j++;
        }
    }
    va_end(ap);
    return (j);
}
