#include "shell.h"

/**
 * get_path - get ptr to PATH
 *
 * Return: ptr to PATH
 */

char *get_path()
{
	char **env = environ;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			return (*env + 5);
		}
		env++;
	}

	return (NULL);
}
