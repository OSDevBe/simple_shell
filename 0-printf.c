#include "main.h"

/**
 * _printf - manual printf
 *
 * @format: arg array of char
 *
 * Return: nbr of printed char Success or -1 ERROR
 */

int _printf(const char *format, ...)
{
	int counter = 0;
	va_list ap;
	func_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"u", print_uint},
		{"m", print_success},
		{"%", print_percent},
		{NULL, NULL}};

	if (format == NULL)
		exit(-1);

	va_start(ap, format);
	counter = fchecker(format, f_list, ap);
	if (counter == -1)
		return (-1);
	va_end(ap);
	return (counter);
}

