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

#define MAX_TOKEN_ARGS 100
#define MAX_PATH_LENGTH 1024

void initialize_args_envp(char *command, char *args[], char *envp[]);
void execute_command(char *exec, char **args, char **envp, char *prog);
size_t _strcspn(const char *str, const char *reject);
void cmd_ninteractive(char *argv[]);
void cmd_interactive(char *argv[]);
void tokenize_command(char *command, char *args[], size_t max_args);
int _strncmp(const char *s1, const char *s2, size_t n);
char *get_path();
int isWhitespace(const char *str);
int _strlen(char *s);
char *copystr(char *src);
char *concatPath(char *str1, char *str2);
char *findExecutable(char *command);

#endif /* _SHELL_H_ */
