#include "shell.h"

/**
 * _strncmp - compare two strins by size @n
 *
 * @s1 : string
 * @s2 : string
 * @n : size of string
 *
 * Return: 0 (SUCCESS) else if not equal
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}

		s1++;
		s2++;
		n--;
	}

	return (0);
}

/**
 * compExit - compare Exit
 *
 * @command : string command
 *
 * Return: 0 (SUCCESS) or -1
 */

int compExit(char *command)
{
	char *tmp = "exit";

	if (_strncmp(command, tmp, 4) == 0)
		return (0);
	return (-1);
}
