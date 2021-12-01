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
