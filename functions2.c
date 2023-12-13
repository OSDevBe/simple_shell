#include "main.h"

/**
 * print_integer - prints integer
 *
 * @ap: List of arguments
 *
 * Return: Will return the amount of characters printed.
 */

int print_integer(va_list ap)
{
	int n, div, len;
	unsigned int num;

	n = va_arg(ap, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	while (num / div > 9)
		div *= 10;

	while (div != 0)
	{
		len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * print_uint - prints unsigned int
 *
 * @ap: List of arguments
 *
 * Return: Will return the amount of characters printed.
 */

int print_uint(va_list ap)
{
	int n, div, len;
	unsigned int num;

	n = va_arg(ap, int);
	div = 1;
	len = 0;

	num = n;

	while (num / div > 9)
		div *= 10;

	while (div != 0)
	{
		len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * print_binary - prints binary
 *
 * @ap: List of arguments
 *
 * Return: Will return the amount of characters printed.
 */

int print_binary(va_list ap)
{
	int i, len = 0, index = 0;
	unsigned int binary[32];
	unsigned int num;

	num = va_arg(ap, unsigned int);

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	while (num > 0)
	{
		binary[index++] = num % 2;
		num /= 2;
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar('0' + binary[i]);
		len++;
	}

	return (len);
}

