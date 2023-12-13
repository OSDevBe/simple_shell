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

int main(int argc, char *argv[], char *envp[])
{
	/* Check if the shell is in interactive mode */
	int interactive = isatty(fileno(stdin));

	/* (void)argc;
	(void)argv;
	(void)envp;*/

	if (!interactive)
	{
		/* None Interactive mode */
		cmd_ninteractive(argv);
	}
	else
	{
		/* Interactive mode */
		cmd_interactive(argv);
	}

	return (0);
}
