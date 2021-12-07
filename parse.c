#include "main.h"

/**
 * tokenize_line - Tokenize a line (string) with delimitators.
 * @line: line to tokenize.
 * Return: an array of strings with tokens-line parts.
 */
char **tokenize_line(char *line)
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
 * tokenize_path - Tokenize a the PATH of a Unix-SO.
 * @path: string with PATH (environ-variable).
 * Return: an array of strings with tokens-PATH directories.
 */
char **tokenize_path(char *path)
{
	int position = 0;
	char *path_line = NULL;
	char **path_tokens = malloc(sizeof(char *) * 1024);

	if (!path_tokens)
	{
		free(path_line);
		return (NULL);
	}

	path_line = strtok(path, ":");
	while (path_line)
	{
		path_tokens[position] = path_line;
		position++;
		path_line = strtok(NULL, ":");
	}
	path_tokens[position] = NULL;

	free(path_line);
	return (path_tokens);
}

/**
 * path_cmd - Search a command into the PATH directories.
 * @path: string with PATH (environ-variable).
 * @cmd: command to find in PATH.
 * Return: a string with the command and its PATH.
 */
char *path_cmd(char *path, char *cmd)
{
	int position = 0;
	char *temporal = NULL;
	char **path_tokens = tokenize_path(path);

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
