#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/syscall.h>

/**
 *
 */
typedef struct to_built
{
	char *cmd;
	int (*f)(char **args);
} builtin;

/* read_functions.c */
char *_strcat(char *dest, char *src);
char *_strconcat(char *str_1, char *srt_2);
int _strlen(char *string);
char *_strcpy(char *arguments, char *if_comand);
int _strcmp(char *s1, char *s2);

/* parse_functions.c */
char **parse_line(char *line);
char *path_cmd(char *cmd);

/* execute_functions.c */
int execute(char **arguments);

/* builtins.c */
int _cd(char **arguments);
int _help(char **arguments);
int __exit(char **arguments);
int _env(char **arguments);
int(*get_builtin(char **arguments))(char **);

#endif /* SHELL_H */
