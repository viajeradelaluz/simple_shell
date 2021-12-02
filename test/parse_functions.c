#include "shell.h"
/**
 *
 */
char **parse_line(char *line)
{
	int position = 0;
	char *token = NULL;
	char **tokens = malloc(sizeof(char *) * 1024);

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
	free(token);

	return (tokens);
}

/**
 *
 */
char *path_cmd(char *cmd)
{
	char path[] = "/bin:/usr/bin:/usr/local/bin:/sbin:/usr/sbin:/usr/local/sbin";
	int position = 0;
	char *path_line = path, *temporal = NULL;
	char **path_tokens = malloc(sizeof(char *) * 1024);

	/* Tokenizing the PATH */
	if (!path_tokens)
		return (NULL);

	path_line = strtok(path, ":");
	while (path_line)
	{
		path_tokens[position] = path_line;
		position++;

		path_line = strtok(NULL, ":");
	}
	path_tokens[position] = NULL;
	free(path_line);

	/* Parsing cmd with the PATH */
	position = 0;
	while (path_tokens[position])
	{
		path_tokens[position] = _strconcat(path_tokens[position], "/");
		temporal = _strconcat(path_tokens[position], cmd);

		if (access(temporal, F_OK) == 0)
		{
			free(path_tokens[position]);
			free(path_tokens);
			return (temporal);
		}
		free(temporal);
		free(path_tokens[position]);
		position++;
	}

	free(path_tokens);
	return (NULL);
}