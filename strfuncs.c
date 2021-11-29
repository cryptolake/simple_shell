#include "main.h"

/**
 * _strlen - get length of string
 *
 * @s: string
 *
 * Return: length
 **/
int _strlen(const char *s)
{
	int i = 0;

	/* if (s[i] == '\0' && s[i+1] == '\0') */
	/* 	return (1); */

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
