#include "main.h"

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
