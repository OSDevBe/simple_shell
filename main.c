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

int main(int __attribute__((unused)) argc,
	char __attribute__((unused)) *argv[], char __attribute__((unused)) *envp[])
{
	/* Check if the shell is in interactive mode */
	int interactive = isatty(fileno(stdin));

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
