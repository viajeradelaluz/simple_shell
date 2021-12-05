#include "main.h"

/**
 * _strconcat - Concatenate two strings reserving memory allocation.
 * @str_1: fist string to concatenate.
 * @str_2: second string to concatenate.
 * Return: the string (*copy) concatenated.
 */
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
 * _strcpy - Copy a string reserving memory allocation.
 * @src: string to copy.
 * @dest: string copied.
 * Return: string (*dest) copied.
 */
char *_strcpy(char *dest, char *src)
{
	int size_src = _strlen(src);
	int counter = 0;

	dest = malloc(sizeof(char *) * (size_src + 1));

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
 * @void: no values to evaluate.
 * Return: a string with the PATH directory.
 */
char *_getPATH(void)
{
	int counter = 0;

	while (environ[counter])
	{
		if (_strstr(environ[counter], "PATH="))
			return (_strcpy(NULL, environ[counter] + 5));
		counter++;
	}

	return (NULL);
}
