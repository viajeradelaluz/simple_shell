#include "shell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	int terminal = 1, read = 0;
	char *line = NULL, *if_command = NULL;
	char **arguments = NULL;
	size_t size_line;

	/* Check if FD is a terminal */
	if (!isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "Is not a terminal\n", 18);
		terminal = 0;
	}

	do
	{
		if (terminal == 1)
			write(STDOUT_FILENO, "($) ", 4);

		/* Read */
		fflush(stdin);
		read = getline(&line, &size_line, stdin);
		if (!read || feof(stdin)) /* Check for EOF */
		{
			free(line);
			exit(EXIT_SUCCESS); /* Is EOF */
		}

		/* Parse and Execute */
		arguments = parse_line(line);

		if_command = path_cmd(arguments[0]);
		if (!if_command)
			return (-1);

		arguments[0] = if_command;

		execute(arguments);

		free(arguments);
		free(if_command);
	} while (1);

	free(line);

	return (0);
}