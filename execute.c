#include "main.h"

/**
 * execute - Create a child process to exectue commands.
 * @arguments: command and arguments to execute.
 * Return: 1 on success, 0 on failure.
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
