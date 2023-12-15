#include "shell.h"

/**
 * isWhitespace - is white space in @str
 *
 * @str : string
 *
 * Return: 0 not just white space, else -1
 */

int isWhitespace(const char *str)
{
	while (*str != '\0')
	{
		if ((*str != ' ') && (*str != '\t'))
		{
			return (0);
		}
		str++;
	}

	return (-1);
}
