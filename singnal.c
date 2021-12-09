#include "main.h"

/**
 * sigint_c - Take the signal of control C to not exit the shell
 * @signal: Signal
 * Return: void
 */
void sigint_c(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n($) ", 5);
}

/**
 * check_comment - Checks if the line contains the # to reemplace for '\0'
 * @line: Line read by getline to check
 * Return: void
 */
void check_comment(char *line)
{
	int i = 0;

	while (*(line + i))
	{
		if (*(line + i) == 35)
		{
			*(line + i) = '\0';
			break;
		}
		i++;
	}
}
