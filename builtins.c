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
int _help(char **arguments __attribute__((unused)))
{
	printf("Type program names and arguments, and hit enter.\n");
	printf("Use the man command for information on other programs.\n");

	return (1);
}

/**
 * __exit - Builting function to execute the exit-command.
 * @arguments: command and arguments to execute.
 * Return: status or 0 on interative terminal, -1 on failure.
 */
int __exit(char **arguments)
{
	int status = 0, i = 0;

	if (arguments[1] == NULL)
		return (2);

	for (i = 0; arguments[1][i]; i++)
	{
		if (arguments[1][i] < 48 || arguments[1][i] > 57)
		{
			fprintf(stderr, "hsh: 1: exit: Illegal number: %s\n", arguments[1]);
			return (-1);
		}
	}
	status = _atoi(arguments[1]);
	return (status);
}

/**
 * _env - Builting function to execute the env-command.
 * @arguments: command and arguments to execute.
 * Return: always 1 (interative status of the terminal).
 */
int _env(char **arguments __attribute__((unused)))
{
	int counter = 0;

	while (environ[counter])
	{
		printf("%s\n", environ[counter]);
		counter++;
	}

	return (1);
}
