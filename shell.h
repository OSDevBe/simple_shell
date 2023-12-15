#ifndef _SHELL_H_
#define _SHELL_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ppheader.h"

extern char **environ;

void initialize_args_envp(char *command, char *args[], char *envp[]);
void execute_command(char **args, char **envp, char *prog);
size_t _strcspn(const char *str, const char *reject);
void cmd_ninteractive(char *argv[]);
void cmd_interactive(char *argv[]);
void tokenize_command(char *command, char *args[], size_t max_args);
int _strncmp(const char *s1, const char *s2, size_t n);
char *get_path();
int isWhitespace(const char *str);

#endif /* _SHELL_H_ */
