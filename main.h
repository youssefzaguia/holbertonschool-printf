#ifndef _PRINTF
#define _PRINTF

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct types - specifier structure for printf
 * @specifiers: pointer to characteres specifiers
 * @f: function pointer to print fucntions
 */
typedef struct types
{
	char specifiers;
	int (*f)(va_list);
} list_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_character(va_list arg);
int print_string(va_list arg);
int print_integer(va_list arg);
int (*print_all(const char c))(va_list);

#endif
