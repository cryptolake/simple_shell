#include "main.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

char *make_path(char *path, char *file)
{
	char *s;

	if (path == NULL || file == NULL)
		return (NULL);

	s = malloc(sizeof(char) *
			(_strlen(path) + _strlen(file) + 2));

	_strcpy(s, path);
	s[_strlen(path)] = '/';
	s[_strlen(path)+1] = '\0';
	_strcat(s, file);

	return (s);
}

char *path_match(char *s)
{
	char **arr_p, *p, *path;
	int i = 0;
	struct stat st;

	path = _strdup(getenv("PATH"));
	arr_p = strtow(path, ":");
	free(path);
	while(arr_p[i] != NULL)
	{
		p = make_path(arr_p[i], s);
		/* printf("\nmake_path = %s\n",p); */

		if (stat(p, &st) == 0)
		{
			free_tow(arr_p);
			return (p);
		}

		free(p);
		i++;
	}

	free_tow(arr_p);
	return (NULL);
}

char *path_handle(char *path)
{
	char *s;
	struct stat st;

	if (stat(path, &st) == 0)
		return (_strdup(path));

	s = path_match(path);
	if (s)
		return (s);

	else
		return (NULL);

}
