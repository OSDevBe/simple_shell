#include "shell.h"


/**
 * cmd_ninteractive - handel command none interactive
 *
 * @argv : prog args
 *
 * Return: void
 */

void cmd_ninteractive(char *argv[])
{
	char *command = NULL, *exec = NULL;
	size_t command_len = 0;
	char *args[MAX_TOKEN_ARGS], *envp[1];

	/* Read from stdin when in non-interactive mode */
	while (getline(&command, &command_len, stdin) != -1)
	{
		/* Remove trailing newline character */
		command[_strcspn(command, "\n")] = '\0';

		if (isWhitespace(command) == 0)
		{
			/* Initialize args and envp */
			initialize_args_envp(command, args, envp);
			if (compExit(command) == 0)
			{
				free(command);
				exit(EXIT_SUCCESS);
			}
			args[0] = exec = findExecutable(args[0]);
			if (exec != NULL)
			{
				execute_command(exec, args, envp, argv[0]);
			}
			else
			{
				_printf("%s: ", argv[0]);
				perror("");
				continue;
			}
		}
		free(command);
		command = NULL;
	}
	free(command);
}

/**
 * cmd_interactive - handel command interactive
 *
 * @argv : prog args
 *
 * Return: void
 */

void cmd_interactive(char *argv[])
{
	char *command = NULL, *exec = NULL;
	size_t command_len = 0;
	char *args[MAX_TOKEN_ARGS], *envp[1];

	while (1)
	{
		_printf("Shell$ ");
		fflush(stdout);

		if (getline(&command, &command_len, stdin) == -1)
		{
			_printf("\n");
			if (command != NULL)
				free(command);
			break;
		}
		command[_strcspn(command, "\n")] = '\0';
		if (isWhitespace(command) == 0)
		{
			initialize_args_envp(command, args, envp);
			if (compExit(command) == 0)
			{
				free(command);
				exit(EXIT_SUCCESS);
			}
			args[0] = exec = findExecutable(args[0]);
			if (exec != NULL)
			{
				execute_command(exec, args, envp, argv[0]);
			}
			else
			{
				_printf("%s: ", argv[0]);
				perror("");
				continue;
			}
		}
		free(command);
		command = NULL;
	}
}
