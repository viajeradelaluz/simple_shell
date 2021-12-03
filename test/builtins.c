#include "shell.h"

/**
 *
 */
int _cd(char **arguments)
{
	if (arguments[1] == NULL)
		fprintf(stderr, "Expected argument to \"cd\"\n");
	else
	{
		if (chdir(arguments[1]) != 0)
			perror("Expected argument to cd");
	}

	return (1);
}

/**
 */
int _help(char **arguments)
{
	(void)arguments;

	printf("Type program names and arguments, and hit enter.\n");
	printf("Use the man command for information on other programs.\n");

	return (1);
}

/**
 *
 */
int __exit(char **arguments)
{
	int status = 0;
	int i;

	if (arguments[1] == NULL)
	{
		exit(status);
	}
	else
	{
		for (i = 0; arguments[1][i]; i++)
		{
			if (arguments[1][i] < 48 || arguments[1][i] > 57)
			{
				perror("No valid");
			}
		}

		status = _atoi(arguments[1]);
		exit(status);
	}
	return (0);
}

/**
 *
 */
int _env(char **arguments)
{
	(void)arguments;
	return (0);
}

/**
 *
 */
int (*get_builtin(char **arguments))(char **)
{
	builtin command[] = {
		{"cd", _cd},
		{"help", _help},
		{"exit", __exit},
		{"env", _env},
		{NULL, NULL}};
	int counter = 0;

	while (command[counter].cmd)
	{
		if (strcmp(arguments[0], command[counter].cmd) == 0)
			return (*(command[counter].f));
		counter++;
	}

	return (NULL);
}
