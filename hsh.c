#include "main.h"

/**
 * main - Program to interprete the command-line.
 * @argc: number of arguments passed to main.
 * @argv: arguments passed to main.
 * @env: array of variables (strings) of the environ.
 * Return: always 0 or EXIT_SUCCESS.
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL, *path = NULL;
	char **arguments = NULL;

	UNUSED(argc), UNUSED(env);

	signal(SIGINT, sigint_c);
	do {
		/* Prompt */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		/* Read */
		path = _getPATH();
		line = read_line(path);

		/* Parse and execute */
		arguments = parse_arguments(path, line, argv);

		free(line), free(path);
		free(arguments);

	} while (1);

	return (EXIT_SUCCESS);
}
