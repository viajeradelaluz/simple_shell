#include "shell.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	int terminal = 1, read;
	char *line = NULL, *if_command = NULL;
	char **arguments = NULL, **path_tokenized = NULL;
	size_t size_line;

	/* Check if FD is a terminal */
	if (!isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "Is not a terminal\n", 18);
		terminal = 0;
	}

	/* Read */
	do
	{
		if (terminal == 1)
			write(STDOUT_FILENO, "($) ", 4);

		fflush(stdin);
		read = getline(&line, &size_line, stdin);
		if (!read)
			return (-1);

		/* Parse and Execute */
		arguments = parse_line(line);
		path_tokenized = tokenize_path();

		if (access(arguments[0], F_OK) != 0)
		{
			if_command = path_cmd(path_tokenized, arguments[0]);
			if (!if_command)
				return (-1);
			arguments[0] = if_command;
		}
		execute(arguments);

	} while (1);

	free(line);
	free(if_command);
	free(arguments);
	free(path_tokenized);
	return (0);
}
/* Thank you! */
/*Daniel Was Here*/ /*Daniel Left*/