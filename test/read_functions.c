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

/**
 *
 */
int _strlen(char *string)
{
	int counter = 0;

	while (string)
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

	free(arguments);
    return (arguments);
}
