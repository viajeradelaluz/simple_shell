#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/syscall.h>

#define UNUSED(x) (void)(x)
#define BUFSIZE 1024

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

/* parse.c */
char **tokenize_line(char *line);
char **tokenize_path(char *path);
char *path_cmd(char *path, char *cmd);

/* execute.c */
char *read_line(char *path);
char **parse_arguments(char *path, char *line, char **argv);
int execute(char **arguments);
char *error_message(char **argv, char **arguments, char *line, char *path);

/* builtins.c */
int(*get_builtin(char **arguments))(char **);
int _cd(char **arguments);
int _help(char **arguments);
int __exit(char **arguments);
int _env(char **arguments);

int history(char *input);
char *_strtok(char *str, char *delim);

void sigint_c(int signal);
void check_comment(char *line);

char *_getline();
void hashtag_handle(char *buff);

#endif /* MAIN_H */
