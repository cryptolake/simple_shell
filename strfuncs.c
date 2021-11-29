#include "main.h"
#include <stddef.h>

/**
 * _strlen - get length of string
 *
 * @s: string
 *
 * Return: length
 **/
size_t _strlen(const char *s)
{
	size_t i = 0;

	if (s == NULL)
		return (0);

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _strcpy - copy a string to another string
 *
 * @dest: destination
 * @src: source
 *
 * Return: pointer string
 **/
char *_strcpy(char *dest, char *src)
{
	int l, i;

	l = _strlen(src);

	for (i = 0; i <= l; i++)
	{
		dest[i] = src[i];
	}

	return (src);
}

/**
 * _strdup - duplicate string in new memory addr
 * @str: string
 *
 * Return: new string addr
 **/
char *_strdup(char *str)
{
	char *s;
	unsigned int l, i;


	if (str == NULL)
	{
		return (NULL);
	}

	else
	{

		l = _strlen(str);
		s = malloc(l + 1);
		if (s == NULL)
		{
			return (NULL);
		}
		for (i = 0; i <= l; i++)
		{
			s[i] = str[i];
		}

	}

	return (s);
}

/**
 * _strcmp - compare two strings and return their difference
 * @s1: string
 * @s2: string
 *
 *
 * Return: difference
 **/
int _strcmp(char *s1, char *s2)
{
	int i, b, d;

	b = 1;
	d = 0;
	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && b; i++)
	{
		if (s1[i] != s2[i])
		{
			d = s1[i] - s2[i];
			b = 0;
		}
	}
	return (d);
}

/**
 * strnon - remove newline from string
 * @str: string
 *
 * Return: string without newline
 **/
char *strnon(char *str)
{
	int l, i = 0, n = 0, j = 0;
	char *s;

	if (str == NULL)
		return (NULL);
	l = _strlen(str);
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	s = malloc(sizeof(char) * ((l + 1) - n));

	i = 0;
	j = 0;

	while (i <= l)
	{
		if (str[i] != '\n')
		{
			s[j] = str[i];
			j++;
		}
		i++;
	}
	free(str);

	return (s);
}
