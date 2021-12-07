#include "main.h"

/**
 * _strtok - Extract tokens from strings.
 * @str: string to break into tokens.
 * @delim: character that delimit the tokens.
 * Return: a pointer to the next token, NULL if there are no more tokens.
 */
char *_strtok(char *str, char *delim)
{
	static char *token;
	static int position;
	char *res = NULL;
	int cont = 0, i = 0, j = 0, flag = 0;

	if (str != NULL)
		token = str, position = 0;
	if (token == NULL || delim == NULL)
		return (NULL);
	if (position >= _strlen(token))
		return (NULL);

	cont = 0;
	for (i = position; token[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (token[i] == delim[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		cont++;
	}

	res = malloc(sizeof(char) * (cont + 1));
	if (!res)
		return (NULL);

	for (i = 0; i < cont; i++)
		res[i] = token[position + i];
	res[i] = '\0';
	position += cont + 1;

	return (res);
}
