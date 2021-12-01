#include "shell.h"
/**
 *
 */
char **parse_line(char *line)
{
	int position = 0;
	char *token = NULL;
	char **tokens = malloc(sizeof(char *) * 64);

	if (!tokens)
		return (NULL);

	token = strtok(line, " \t\r\n\a");
	while (token)
	{
		tokens[position] = token;
		position++;

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 *
 */
char *path_cmd(char *cmd)
{
	char line[] = "/bin:/usr/bin:/usr/local/bin";
	int position = 0;
	char *path_line = line, *temporal = NULL;
	char **path_tokens = malloc(sizeof(char *) * 64);

	if (!path_tokens)
		return (NULL);

	path_line = strtok(line, ":");
	while (path_line)
	{
		path_tokens[position] = path_line;
		position++;

		path_line = strtok(NULL, ":");
	}
	path_tokens[position] = NULL;

	position = 0;
	while (path_tokens[position])
	{
		path_tokens[position] = _strcat(path_tokens[position], "/");
		temporal = _strcat(path_tokens[position], cmd);
		printf("%s\n", path_tokens[position]);

		if (access(temporal, F_OK) == 0)
		{
			free(path_tokens);
			return (temporal);
		}
		position++;
	}
	free(path_tokens);
	return (NULL);
}
