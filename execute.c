#include "main.h"

/**
 * read_line - Getline from stdin.
 * @path: string with PATH (environ-variable).
 * Return: a string with the stdin-line.
 */
char *read_line(char *path)
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
		
		free(line), free(path);
		exit(EXIT_SUCCESS); /* Is EOF */
	}
	history(line);
	return (line);
}

/**
 * parse_arguments - Define if a command is builting or no-builting.
 * @path: string with PATH (environ-variable).
 * @line: stdin-line from prompt.
 * @argv: arguments passed to main.
 * Return: an array of arguments (strings) ready to be executed.
 */
char **parse_arguments(char *path, char *line, char **argv)
{
	int (*f)(char **), status = 1;
	char *is_command = NULL;
	char **arguments = tokenize_line(line);

	if (arguments[0] == NULL)
	{
		free(arguments);
		return (NULL);
	}
	/* Check if command is in PATH */
	if (access(arguments[0], F_OK) != 0)
	{
		/* Check if command is a builtin */
		f = get_builtin(arguments);
		if (!f)
		{ /* Check if command is not a builtin */
			is_command = path_cmd(path, arguments[0]);
			if (!is_command)
			{
				error_message(argv, arguments);
				free(arguments), free(is_command);
				return (NULL);
			}
			arguments[0] = is_command;

			/* Execute command as no-builting */
			execute(arguments), free(is_command);
		}
		else
		{ /* Execute command as builting */
			status = f(arguments);
			if (status == 0 || status > 1 ||
				((_strcmp(arguments[0], "exit") == 0) && (status == 1)))
				free(line), free(path), free(arguments), exit(status);
		}
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

/**
 * error_message - Print errors for the status of the terminal.
 * @argv: arguments passed to main.
 * @arguments: command and arguments to execute.
 * Return: no return.
 */
void error_message(char **argv, char **arguments)
{
	if (isatty(STDIN_FILENO) == 0)
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], arguments[0]);
	else
		fprintf(stderr, "%s: not found\n", arguments[0]);
}
