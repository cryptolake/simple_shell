#include "main.h"
#include "strtow.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int is_dir(char *file)
{
	struct stat st;

	if (stat(file, &st) == 0)
		return (S_ISDIR(st.st_mode));

	else
		return (0);
}

int is_path(char *s)
{
	if (_strlen(s) >= 2)
	{
		if ((s[0] == '.' && s[1] == '/') || s[0] == '/' ||
			(s[0] == '.' && s[1] == '.' && s[2] == '/'))
			return (1);
	}

	return (0);
}

char *make_path(char *path, char *file)
{
	char *s;

	if (path == NULL || file == NULL)
		return (NULL);

	s = malloc(sizeof(char) *
			(_strlen(path) + _strlen(file) + 2));
	if (!s)
		return (NULL);

	_strcpy(s, path);
	s[_strlen(path)] = '/';
	s[_strlen(path)+1] = '\0';
	_strcat(s, file);

	return (s);
}

char *path_match(char **s)
{
	char **arr_p, *p, *path;
	int i = 0;
	struct stat st;

	path = _getenv("PATH");
	if (_strlen(path) == 0)
		return (NULL);

	arr_p = strtow(path, ':');
	if (!arr_p)
		return (NULL);

	while(arr_p[i] != NULL)
	{

		p = make_path(arr_p[i], *s);
		if (stat(p, &st) == 0)
		{
			free(*s);
			*s = p;
			free_tow(arr_p);
			return (p);
		}

		free(p);
		i++;
	}

	free_tow(arr_p);
	return (NULL);
}
