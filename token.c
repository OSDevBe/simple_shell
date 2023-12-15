#include "shell.h"

/**
 * tokenize_command - tokenize command
 *
 * @command : command string
 * @args : table of args
 * @max_args : max args
 *
 * Return: void
 */

void tokenize_command(char *command, char *args[], size_t max_args)
{
	size_t i = 0;
	char *token = strtok(command, " ");

	while (token != NULL && i < max_args - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;
}

/**
 * initialize_args_envp - init
 *
 * @command : string command
 * @args : args
 * @envp : enviroment
 *
 * Return: VOID
 */

void initialize_args_envp(char *command, char *args[], char *envp[])
{
	trimSpaces(command);
	tokenize_command(command, args, MAX_TOKEN_ARGS);
	envp[0] = NULL;
}
