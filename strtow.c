#include "main.h"

/**
 * strtow - split a string into words
 *
 * @str: string
 * @del: delimiter
 *
 * Return: array of words
 **/
char **strtow(char *str, char *del)
{
	char **s = NULL;
	char *t;
	size_t i = 0;

	t = strtok(str, del);
	if (!t)
		return (NULL);

	while (t)
	{
		s = _realloc(s, sizeof(char *) * i, sizeof(char *) * (i + 1));

		s[i] = malloc(_strlen(t) + 1);
		_memcpy(s[i], t, _strlen(t) + 1);

		t = strtok(NULL, del);
		i++;
	}

	s = _realloc(s, sizeof(char *) * i, sizeof(char *) * (i + 1));
	s[i] = t;

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
