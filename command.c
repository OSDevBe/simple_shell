#include "shell.h"

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
	args[0] = command;
	args[1] = NULL;
	envp[0] = NULL;
}

/**
 * execute_command - exec command
 *
 * @command : string command
 * @prog : name of program
 *
 *Return: VOID
 */

void execute_command(char *command, char *prog)
{
	char *args[2];
	char *envp[1];

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

		/* Initialize args and envp */
		initialize_args_envp(command, args, envp);

		/* Execute the command using execve */
		if (execve(command, args, envp) == -1)
		{
			/* Handle execution error */
			_printf("%s : ", prog);
			perror("");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process
		 Wait for the child to complete */
		int status;
		waitpid(pid, &status, 0);
		
	}
}