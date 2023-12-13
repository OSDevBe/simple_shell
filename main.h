#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

/**
 * struct ffunc - defines a structure for char and functions
 *
 * @c: symbol
 *
 * @f: function
 */
struct ffunc
{
	char *c;
	int (*f)();
};
typedef struct ffunc func_t;

int _putchar(char c);
int fchecker(const char *format, func_t f_list[], va_list ap);
int _printf(const char *format, ...);
int print_char(va_list ap);
int print_string(va_list ap);
int print_success(void);
int print_percent(void);
int print_integer(va_list ap);
int print_uint(va_list ap);
int print_binary(va_list ap);

#endif /* _MAIN_H_ */

