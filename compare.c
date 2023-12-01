#include "shell.h"

/**
 * _strcspn - compare str with reject and return count
 *
 * @str : string
 * @reject : string
 *
 * Return: count
 */

size_t _strcspn(const char *str, const char *reject)
{
	const char *s = str;
	size_t count = 0;

	while (*s)
	{
		const char *r = reject;
		while (*r)
		{
			if (*s == *r)
			{
				return count;
			}
			++r;
		}
		++s;
		++count;
	}

	return count;
}