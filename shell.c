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
	char *line = NULL;
	char **arguments = NULL;

	(void)argc, (void)argv, (void)env;
/* 	UNUSED(argc), UNUSED(argv), UNUSED(env); */

	do {
		/* Prompt */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		/* Read */
		line = read_line();

		/* Parse and execute */
		arguments = parse_arguments(line);

		free(line);
		free(arguments);

	} while (1);

	return (EXIT_SUCCESS);
}