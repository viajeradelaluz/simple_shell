#include "main.h"

/**
 * get_builtin - Check if a hsh-command is a builting.
 * @arguments: command and arguments to evaluate.
 * Return: a function-potiner to execute de hsh-command, NULL on failure.
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
		if (_strcmp(arguments[0], command[counter].cmd) == 0)
			return (*(command[counter].f));
		counter++;
	}

	return (NULL);
}

/**
 * _cd - Builting function to execute the cd-command.
 * @arguments: command and arguments to execute.
 * Return: always 1 (interative status of the terminal).
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
 * _help - Builting function to execute the help-command.
 * @arguments: command and arguments to execute.
 * Return: always 1 (interative status of the terminal).
 */
int _help(char **arguments)
{
	(void)arguments;

	printf("Type program names and arguments, and hit enter.\n");
	printf("Use the man command for information on other programs.\n");

	return (1);
}

/**
 * __exit - Builting function to execute the exit-command.
 * @arguments: command and arguments to execute.
 * Return: always 0 (end of interative status of the terminal).
 */
int __exit(char **arguments)
{
	int status = 0, i = 0;

	if (arguments[1] == NULL)
		exit(status);
	else
	{
		for (i = 0; arguments[1][i]; i++)
		{
			if (arguments[1][i] < 48 || arguments[1][i] > 57)
				perror("No valid");
		}

		status = _atoi(arguments[1]);
		exit(status);
	}

	return (0);
}

/**
 * _env - Builting function to execute the env-command.
 * @arguments: command and arguments to execute.
 * Return: always 1 (interative status of the terminal).
 */
int _env(char **arguments)
{
	int counter = 0;
	(void)arguments;

	while (environ[counter])
	{
		printf("%s\n", environ[counter]);
		counter++;
	}

	return (1);
}
