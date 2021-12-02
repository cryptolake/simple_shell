#include "main.h"
#include <stddef.h>

/**
* _strcat - concatonate two strings
* @dest: string to contonate into
* @src: string to add
*
* Return: pointer of dest
**/
char *_strcat(char *dest, char *src)
{
	int ls, ld, i;

	ls = strlen(src);
	ld = strlen(dest);

	for (i = 0; i < ls; i++)
	{
		dest[ld + i] = src[i];
	}
	dest[ls + ld] = '\0';


	return (dest);
}


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
int _strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (s1[i] - s2[i]);
}

