#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/syscall.h>

int _strlen(char *string);
char *_strcat(char *dest, char *src);
char **parse_line(char *line);
char **tokenize_path(void);
char *path_cmd(char **path_tokens, char *cmd);
int execute(char **arguments);

#endif /* SHELL_H */
