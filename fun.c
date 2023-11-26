#include "main.h"
/**
 * print_character - printf character
 * Return: -1,1
 */

int print_character(va_list arg)
{

    int ch = va_arg(arg, int);

    if (ch < 0 || ch > 127)
    {
        return (-1);
    }

    _putchar(ch);
    return (1);
}
/**
 * print_string - printf string
 * Return: i
 */

int print_string(va_list arg)
{
    int i;
    char *str = va_arg(arg, char *);

    if (str == NULL)
    {
        write(1, "(null)", 6);
        return (6);
    }

    for (i = 0; str[i] != '\0'; i++)
    {
        _putchar(str[i]);
    }

    return (i);
}
/**
 * print_integer - printf integer
 * Return: 0
 */

int print_integer(va_list arg)
{
    long int num = va_arg(arg, int);
    int decimal = 1, i = 0;
    long int digitaux;

    if (num < 0)
    {
        i += _putchar('-');
        num *= -1;
    }

    if (num < 10)
        return (i += _putchar(num + '0'));

    digitaux = num;

    while (digitaux > 9)
    {
        decimal *= 10;
        digitaux /= 10;
    }
    while (decimal >= 1)
    {
        i += _putchar(((num / decimal) % 10) + '0');
        decimal /= 10;
    }

    return (i);
}
