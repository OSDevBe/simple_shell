#include "shell.h"

/**
 * main - simple shell
 *
 * Description : simple shell
 * @argc : nmbr of arguments
 * @argv : value of arguments
 * @envp : enviroment variable
 *
 *Return: Always 0 (Success)
 */

int main(int __attribute__((unused)) argc, char __attribute__((unused)) * argv[], char __attribute__((unused)) *envp[])
{
	char *command = NULL;
	size_t command_len = 0;

	/* Check if the shell is in interactive mode */
	int interactive = isatty(fileno(stdin));

	if (!interactive)
	{
		/* Read from stdin when in non-interactive mode */
		while (getline(&command, &command_len, stdin) != -1)
		{
			/* Remove trailing newline character */
			command[_strcspn(command, "\n")] = '\0';

			/* Execute the command */
			execute_command(command, argv[0]);

			/* Free allocated memory */
			free(command);
			command = NULL;
		}
	}
	else
	{
		/* Interactive mode */
		while (1)
		{
			/* Display prompt */
			_printf("Shell> ");
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

			/* Execute the command */
			execute_command(command, argv[0]);

			/* Free allocated memory */
			free(command);
			command = NULL;
		}
	}

	free(command);

	return (0);
}
