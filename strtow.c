#include <stdlib.h>

/**
 * _strlen - get length of string
 *
 * @s: string
 *
 * Return: length
 **/
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * word_count - count words
 * @str: string
 *
 * Return: number of words
 **/
int word_count(char *str, char del)
{
	int i,
		x = 0,
		l;

	l = _strlen(str);

	for (i = 0; i < l; i++)
	{
		if (str[i] != del)
		{
			x++;
			while (str[i] != del && str[i])
				i++;
		}
	}

	return (x);
}

/**
 * len_words - get length of each word
 *
 * @str: string
 *
 * Return: array of length of each word
 **/
int *len_words(char *str, char del)
{
	int x,
		i,
		j = 0,
		wc = 0,
		l;

	int *y;

	l = _strlen(str);
	x = word_count(str, del);
	y = malloc(sizeof(int) * x);

	for (i = 0; i < l; i++)
	{
		j = 0;
		if (str[i] != del)
		{
			while (str[i] != del && i < l)
			{
				i++;
				j++;
			}
			y[wc] = j;
			wc++;
		}
	}

	return (y);
}

/**
 * strtow - split a string into words
 *
 * @str: string
 *
 * Return: array of strings of words
 **/
char **strtow(char *str, char del)
{
	char **s;
	int i = 0, w = 0, j, l, wc, *y;

	if (str == NULL)
		return (NULL);

	wc = word_count(str, del);
	if (wc == 0)
		return (NULL);

	l = _strlen(str);
	y = len_words(str, del);
	s = malloc(sizeof(char *) * (wc + 1));

	for (i = 0; i < wc; i++)
		s[i] = malloc(sizeof(char) * (y[i] + 1));

	w = 0;
	for (i = 0; i < l; i++)
	{
		if (str[i] != del)
		{
			for (j = 0; j < y[w]; j++)
			{
				s[w][j] = str[i];
				i++;
			}
			s[w][j] = '\0';
			w++;
		}
	}

	free(y);
	s[w] = NULL;

	return (s);
}

void free_tow(char **tow)
{
	int i = 0;

	while (tow[i])
		free(tow[i++]);
	free(tow);
}
