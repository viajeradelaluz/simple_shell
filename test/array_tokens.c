#include "shell.h"

char **array_tokens(char *line)
{
	int position = 0;
	char *token = NULL;
	char **tokens = malloc(sizeof(char *) * 64);

	if (!tokens)
		return (NULL);

	token = strtok(line, " ");
	while (token)
	{
		printf("%s| ", token);
		tokens[position] = token;
		position++;

		token = strtok(NULL, ":,");
	}
	tokens[position] = NULL;
	return (tokens);
}

int main()
{
	char line[] = "Es un dibujo: gatos, muy lindos.";
	char **tokens = NULL;

	tokens = array_tokens(line);
	printf("\n%s, %s, %s\n", tokens[3], tokens[1], tokens[2]);

	free(tokens);
	return (0);
}
