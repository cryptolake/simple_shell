#include "main.h"
#include <stddef.h>


/**
 * strtow - split a string into tokens by delimeter
 *
 * @str: string
 * @del: delimeter
 *
 * Return: array of strings of tokens
 **/
char **strtow(const char *str, const char del)
{
	char **s = NULL;
	int i = 0, j, w = 0;

	while (str[i] != '\0' && str[i] == del)
		i++;
	if (!str[i])
		return (NULL);

	i = 0;
	while (str[i])
	{
		j = i;
		if (str[i] != del)
		{
			s = _realloc(s, sizeof(char *) * w,
						sizeof(char *) * (w + 1));
			s[w] = NULL;
			while (str[j] && str[j] != del)
			{
				s[w] = _realloc(s[w], sizeof(char) * (j - i), sizeof(char) * ((j - i) + 1));
				s[w][j - i] = str[j];
				j++;
			}
			s[w] = _realloc(s[w], sizeof(char) * (j - i), sizeof(char) * ((j - i) + 1));
			s[w][j-i] = '\0';
			i += (j - i);
			w++;
		}

		else
			i++;
	}
	s = _realloc(s, sizeof(char *) * w, sizeof(char *) * (w + 1));
	s[w] = NULL;

	return (s);
}

/**
 * free_tow - free the array
 * @tow: array
 *
 **/
void free_tow(char **tow)
{
	int i = 0;

	while (tow[i])
		free(tow[i++]);
	free(tow);
}

/**
 * len_tow - number of elements in tow array
 * @av: array
 *
 * Return: length of array
 **/
size_t len_tow(char **av)
{
	size_t i = 0;

	while (av[i])
		i++;

	return (i);
}
