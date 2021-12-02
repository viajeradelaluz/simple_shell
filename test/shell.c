#include "shell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	int terminal = 1, read;
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
		/* Read */
		if (terminal == 1)
			write(STDOUT_FILENO, "($) ", 4);

		fflush(stdin);
		read = getline(&line, &size_line, stdin);
		if (!read)
			return (-1);

		/* Parse and Execute */
		arguments = parse_line(line);

		if_command = path_cmd(arguments[0]);
		if (!if_command)
			return (-1);

		arguments[0] = if_command;

		execute(arguments);

	} while (1);

	free(line);
	free(arguments);
	return (0);
}
