#include "main.h"

/**
 * print_char - Prints character
 *
 * @ap: list of arguments
 *
 * Return: Will return the amount of characters printed.
 */

int print_char(va_list ap)
{
	_putchar(va_arg(ap, int));
	return (1);
}

/**
 * print_percent - Prints percent
 *
 * Return: Will return the amount of characters printed.
 */

int print_percent(void)
{
	_putchar('%');
	return (1);
}

/**
 * print_string - Prints a string
 *
 * @ap: list of arguments
 *
 * Return: Will return the amount of characters printed.
 */

int print_string(va_list ap)
{
	int i;
	char *str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_success - Prints a success for %m
 *
 * Return: Will return the amount of characters printed.
 */

int print_success(void)
{
	int i;
	char *str;

	str = "Success";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

