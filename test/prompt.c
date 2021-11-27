#include "shell.h"

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;

	int terminal = 1, bytes_readed = 0;
	char * line = NULL;
	size_t size_line;


	if (!isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "Its not a terminal\n", 18);
		terminal = 0;
	}

	do
	{
		if (terminal == 1)
			write(STDOUT_FILENO, "($) ", 4);
		
		bytes_readed = getline(&line, &size_line, stdin);



	 } while (1);
}
