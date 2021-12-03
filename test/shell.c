#include "shell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc, (void)argv, (void)env;

	int read = 0;
	int (*f)(char **);
	char *line = NULL, *if_command = NULL;
	char **arguments = NULL;
	size_t size_line;

	do
	{
		if (isatty(STDIN_FILENO))
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

		if (access(arguments[0], F_OK) != 0) /* Check if input is in PATH */
		{
			f = get_builtin(arguments); /* Check if input is a builtin */
			if (!f)
			{
				if_command = path_cmd(arguments[0]); /* Check if input is not a builtin */
				if (!if_command)
				{
					perror("Command not found");
					free(arguments), free(if_command);
					continue;
				}
				arguments[0] = if_command;

				execute(arguments), free(if_command);
			}
			else
				f(arguments), f = NULL;				
		}
		else
			execute(arguments);

		free(arguments);

	} while (1);

	free(line);

	return (0);
}
