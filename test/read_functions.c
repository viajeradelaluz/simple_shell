#include "shell.h"

/**
 * _strcat - Append two strings.
 * @dest: String destination.
 * @src: String input.
 * Return: Destination.
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p != '\0')
		p++;

	while (*src != '\0')
		*p++ = *src++;
	*p = '\0';

	return (dest);
}

char *_strconcat(char *str_1, char *str_2)
{
	int size_str_1 = _strlen(str_1);
	int size_str_2 = _strlen(str_2);
	char *p = NULL;
	char *copy = malloc(sizeof(char *) * (size_str_1 + size_str_2 + 1));

	if (!copy)
		return (NULL);

	p = copy;
	while (*str_1)
		*p++ = *str_1++;

	while (*str_2)
		*p++ = *str_2++;

	*p = '\0';

	return (copy);
}

/**
 *
 */

int _strlen(char *string)
{
	int counter = 0;

	while (*(string + counter))
		counter++;

	return (counter);
}

/**
 *
 */
char *_strcpy(char *arguments, char *if_comand)
{
	int size_if_comand = _strlen(if_comand);
	int counter = 0;

	arguments = malloc(sizeof(char *) * (size_if_comand + 1));

	if (!arguments)
		return (NULL);

	while (if_comand[counter])
	{
		arguments[counter] = if_comand[counter];
		counter++;
	}
	arguments[counter] = if_comand[counter];

	return (arguments);
}
