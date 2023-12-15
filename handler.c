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
	char *command = NULL;
	size_t command_len = 0;
	char *args[100], *envp[1];

	/* Read from stdin when in non-interactive mode */
	while (getline(&command, &command_len, stdin) != -1)
	{
		/* Remove trailing newline character */
		command[_strcspn(command, "\n")] = '\0';

		if (isWhitespace(command) == 0)
		{
			/* Initialize args and envp */
			initialize_args_envp(command, args, envp);
			/* Execute the command */
			execute_command(args, envp, argv[0]);
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
	char *command = NULL;
	size_t command_len = 0;
	char *args[100], *envp[1];

	while (1)
	{
		/* Display prompt */
		_printf("Shell$ ");
		fflush(stdout);

		/* Read command from user using getline */
		if (getline(&command, &command_len, stdin) == -1)
		{
			/* Handle end of file (Ctrl+D) */
			_printf("\n");
			break;
		}

		/* Remove trailing newline character */
		command[_strcspn(command, "\n")] = '\0';

		if (isWhitespace(command) == 0)
		{
			/* Initialize args and envp */
			initialize_args_envp(command, args, envp);
			/* Execute the command */
			execute_command(args, envp, argv[0]);
		}
		/* Free allocated memory */
		free(command);
		command = NULL;
	}
	free(command);
}
