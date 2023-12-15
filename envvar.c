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

/**
 * findExecutable - find executable
 *
 * @command : command
 *
 * Return: command if found or NULL
 */

char *findExecutable(char *command)
{
	char *fullPath;
	char *path = copystr(get_path());

	char *token = strtok(path, ":");

	if (access(command, X_OK) == 0)
	{
		free(path);
		return (copystr(command));
	}

	while (token != NULL)
	{
		fullPath = concatPath(token, command);

		if (access(fullPath, X_OK) == 0)
		{
			free(path);
			return (fullPath);
		}
		free(fullPath);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
