#include "main.h"

/**
 * _strcat - append two strings.
 * @dest: string destination.
 * @src: string input.
 * Return: destination.
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
 * _strcmp - Compare two strings.
 * @s1: first string to compare.
 * @s2: seconde string to compare.
 * Return: 0 if *s1 and *s2 are equal,
 * -1 if *s1 is less than *s2, 1 if *s1 is greater than *s2.
 */
int _strcmp(char *s1, char *s2)
{
	int counter = 0, comparison = 0;

	while (s1[counter] && s2[counter])
	{
		if (s1[counter] != s2[counter])
		{
			comparison = s1[counter] - s2[counter];
			break;
		}
		counter++;
	}

	return (comparison);
}

/**
 * _strstr - Locate a substring.
 * @environ: string in which to look at.
 * @path: substring to find.
 * Return: 1 on success, 0 on failure.
 */
int _strstr(char *environ, char *path)
{
	char *env = environ;
	char *_path = path;

	environ = env;

	while (*_path != '\0' && *env == *_path)
	{
		env++, _path++;
		if (*_path == '\0')
			return (1);
	}

	return (0);
}

/**
 * _strlen - Calculate the length of a string
 * @string: string to be counted.
 * Return: number of bytes in the string.
 */
int _strlen(char *string)
{
	int counter = 0;

	while (*(string + counter))
		counter++;

	return (counter);
}
/**
 * _atoi - Convert a string to an integer
 * @string: string to convert
 * Return: the converted value, 0 on failure.
 */
int _atoi(char *string)
{
	int a = 0, b = 0, d = 0, c = 0;
	unsigned int conversion = 0;

	while (string[a] != '\0')
		d++, a++;

	for (b = 0 + c; b <= d - 1; b++)
	{
		if (string[b] >= 48 && string[b] <= 57)
		{
			conversion = ((conversion * 10) + string[b] - '0');
			if (string[b + 1] < 48 || string[b + 1] > 57)
				break;
		}
	}

	c = 0;
	b = 0;
	while (c != 1)
	{
		if (string[b] >= 48 && string[b] <= 57)
			c = 1;
		if (string[b] == 45)
			conversion = (conversion * -1);
		b++;
	}
	return (conversion);
}
