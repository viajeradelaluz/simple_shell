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
char *_strconcat(char *str_1, char *srt_2);
char *_strcpy(char *arguments, char *if_comand);
char **parse_line(char *line);
char *path_cmd(char *cmd);
int execute(char **arguments);

#endif /* SHELL_H */
