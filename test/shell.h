#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char **parse_line(char *line);
char **tokenize_path(char *argv_0);
int execute(char **arguments);

#endif /* SHELL_H */
