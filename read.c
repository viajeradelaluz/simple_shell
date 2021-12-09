#include "main.h"

/**
 * _strconcat - Concatenate two strings reserving memory allocation.
 * @str_1: fist string to concatenate.
 * @str_2: second string to concatenate.
 * Return: the string (*copy) concatenated.
 */
char *_strconcat(char *str_1, char *str_2)
{
	int size = _strlen(str_1) + _strlen(str_2) + 1;
	char *temporal = NULL;

	char *copy = malloc(sizeof(char *) * size);

	if (!copy)
		return (NULL);

	temporal = copy;
	while (*str_1)
		*temporal++ = *str_1++;

	while (*str_2)
		*temporal++ = *str_2++;

	*temporal = '\0';

	return (copy);
}

/**
 * _strcpy - Copy a string reserving memory allocation.
 * @src: string to copy.
 * @dest: string copied.
 * Return: string (*dest) copied.
 */
char *_strcpy(char *dest, char *src)
{
	int size = _strlen(src) + 1;
	int counter = 0;

	dest = malloc(sizeof(char *) * size);
	if (!dest)
		return (NULL);

	while (src[counter])
	{
		dest[counter] = src[counter];
		counter++;
	}
	dest[counter] = src[counter];

	return (dest);
}

/**
 * _getPATH - Find PATH directory of a Unix-OS
 * @void: no arguments to pass.
 * Return: a string with the PATH directory.
 */
char *_getPATH(void)
{
	int counter = 0;
	char *path = NULL;

	while (environ[counter])
	{
		if (_strcmp(environ[counter], "PATH=") == 0)
		{
			path = _strcpy(NULL, environ[counter] + 6);
			return (path);
		}
		counter++;
	}

	return (NULL);
}
