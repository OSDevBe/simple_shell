#include "shell.h"

/**
 * execute_command - exec command
 *
 * @args : string command
 * @envp : environ variable
 * @prog : name of program
 *
 *Return: VOID
 */

void execute_command(char **args, char **envp, char *prog)
{
	int status;

	/* Fork a child process */
	pid_t pid = fork();

	if (pid == -1)
	{
		/* Forking error */
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		/* Execute the command using execve */
		if (execve(args[0], args, envp) == -1)
		{
			/* Handle execution error */
			_printf("%s: ", prog);
			perror("");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		/* Wait for the child to complete */
		waitpid(pid, &status, 0);
		if (!WIFEXITED(status))
		{
			/* Command execution error */
			_printf("Command execution error\n");
		}
	}
}
