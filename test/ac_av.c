
#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
	(void)ac;
	char *arguments;
	int counter = 0, nchars = strlen(*av);

	while (av)
	{
		arguments = av[counter];
		printf("%s ", arguments);
		counter++;
		if (counter >= (nchars - 2))
			break;
	}
	printf("\n");
	return (counter);
}
