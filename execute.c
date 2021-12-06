#include "main.h"

/**
 * read_line - Getline from stdin.
 * @void: values to analize are from stdin.
 * Return: a string with the stdin-line.
 */
char *read_line(void)
{
	int read = 0;
	char *line = NULL;
	size_t size_line;

	/* Read line */
	fflush(stdin);
	read = getline(&line, &size_line, stdin);

	/* Check for EOF*/
	if (!read || feof(stdin))
	{
		free(line);
		exit(EXIT_SUCCESS); /* Is EOF */
	}

	return (line);
}

/**
 * parse_arguments - Define if a command is builting or no-builting.
 * @line: stdin-line from prompt.
 * Return: an array of arguments (strings) ready to be executed.
 */
char **parse_arguments(char *line)
{
	int (*f)(char **);
	char *if_command = NULL;
	char **arguments = tokenize_line(line);

	/* Check if command is in PATH */
	if (access(arguments[0], F_OK) != 0)
	{
		/* Check if command is a builtin */
		f = get_builtin(arguments);
		if (!f)
		{
			/* Check if command is not a builtin */
			if_command = path_cmd(arguments[0]);
			if (!if_command)
			{
				perror("Command not found");
				free(arguments), free(if_command);
				return (NULL);
			}
			arguments[0] = if_command;

			/* Execute command as no-builting */
			execute(arguments), free(if_command);
		}
		else
			f(arguments), f = NULL; /* Execute command as builting */
	}
	else
		execute(arguments); /* Execute command in PATH */

	return (arguments);
}

/**
 * execute - Create a child process to exectue commands.
 * @arguments: command and arguments to execute.
 * Return: always 1 (interative status of the terminal).
 */
int execute(char **arguments)
{
	int status = 0;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid >= 0) /* Fork was successful */
	{
		if (child_pid == 0) /* Child process */
		{
			execve(arguments[0], arguments, NULL);
			exit(0);
		}
		else /* Parent process */
			wait(&status);
	}
	else /* Fork failed */
	{
		perror("Error: child process not neccessary");
		return (1);
	}

	return (1);
}