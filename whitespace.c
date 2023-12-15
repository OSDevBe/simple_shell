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

/**
 * _strlen - manual strlen
 *
 * @s: arg string ptr
 *
 * Return: s length
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * copystr - manual strlen
 *
 * @src: arg string ptr
 *
 * Return: string
 */

char *copystr(char *src)
{
	size_t i = 0;
	size_t length = _strlen(src) + 1;

	char *dest = (char *)malloc(length);

	if (dest == NULL)
	{
		exit(EXIT_FAILURE);
	}

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}

/**
 * trimSpaces - trim spaces
 *
 * @src: arg string ptr
 *
 * Return: void
 */

void trimSpaces(char *str)
{
	int start = 0, end, i;

	while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
	{
		start++;
	}

	if (str[start] == '\0')
	{
		str[0] = '\0';
		return;
	}

	end = start;
	while (str[end] != '\0')
	{
		end++;
	}
	end--;

	while (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')
	{
		end--;
	}

	for (i = 0; start <= end; i++, start++)
	{
		str[i] = str[start];
	}
	str[i] = '\0';
}
