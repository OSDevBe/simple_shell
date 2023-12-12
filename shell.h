#ifndef _SHELL_H_
#define _SHELL_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "./printf/main.h"

#define MAX_COMMAND_LENGTH 100

void execute_command(char *command, char *prog);
size_t _strcspn(const char *str, const char *reject);
void cmd_ninteractive(char *argv[]);
void cmd_interactive(char *argv[]);
void tokenize_command(char *command, char *args[], size_t max_args);

#endif /* _SHELL_H_ */
