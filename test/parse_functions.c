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
char **tokenize_path(void)
{
	char line[] = "/bin:/usr/bin:/usr/local/bin";
	int position = 0;
	char *path_line = line;
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
	return (path_tokens);
}

/**
 * 
 */
char *path_cmd(char **path_tokens, char *cmd)
{
	int position = 0;
	char *temporal = NULL;

	while (path_tokens[position])
	{
 		path_tokens[position] = strcat(path_tokens[position], "/");
		temporal = strcat(path_tokens[position], cmd);
		printf("%s", path_tokens[position]);

		if (access(temporal, F_OK) == 0)
			return (temporal);
		position++;
	}
	return (NULL);
}
