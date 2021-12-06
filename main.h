#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/syscall.h>

/**
 * struct to_built - Check if a hsh-command is a builting.
 * @cmd: hsh-command to evaluate.
 * @f: funtion to execute if cmd is a builting.
 */
typedef struct to_built
{
	char *cmd;
	int (*f)(char **args);
} builtin;

extern char **environ;

/* strings.c */
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strstr(char *environ, char *path);
int _strlen(char *string);
int _atoi(char *s);

/* read.c */
char *_strconcat(char *str_1, char *srt_2);
char *_strcpy(char *dest, char *src);
char *_getPATH(void);
void free_malloc(char *string);

/* parse.c */
char **tokenize_line(char *line);
char **tokenize_path(void);
char *path_cmd(char *cmd);

/* execute.c */
char *read_line();
char **parse_arguments(char *line);
int execute(char **arguments);

/* builtins.c */
int(*get_builtin(char **arguments))(char **);
int _cd(char **arguments);
int _help(char **arguments);
int __exit(char **arguments);
int _env(char **env);

char *_strtok(char *str, char *delim);

/* #define UNUSED(x) (void)(x); */
#define RAII_VARIABLE() \

#endif /* MAIN_H */

