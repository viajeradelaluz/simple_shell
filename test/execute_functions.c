#include "shell.h"

/**
 *
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
		perror("Error:");
		return (1);
	}

	return (1);
}

/**
 * _atoi - convert a string to an integer
 * @s: String to convert
 * Description: convert a string to an integer.
 * Return: void
 */
int _atoi(char *s)
{
	int i;
	int j;
	int l;
	unsigned int a;
	int cont;

	i = 0;
	l = 0;
	while (s[i] != '\0')
	{
		l++;
		i++;
	}

	cont = 0;
	a = 0;

	for (j = 0 + cont; j <= l - 1; j++)
	{
		if (s[j] >= 48 && s[j] <= 57)
		{
			a = ((a * 10) + s[j] - '0');
			if (s[j + 1] < 48 || s[j + 1] > 57)
				break;
		}
	}

	cont = 0;
	j = 0;
	while (cont != 1)
	{
		if (s[j] >= 48 && s[j] <= 57)
			cont = 1;
		if (s[j] == 45)
			a = (a * -1);
		j++;
	}
	return (a);
}