#include "main.h"
#include "strtow.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * is_dir - is file a directory
 * @file: path to file
 * Return: (0) not a dir (1) is dir
 **/
int is_dir(char *file)
{
	struct stat st;

	if (stat(file, &st) == 0)
		return (S_ISDIR(st.st_mode));

	else
		return (0);
}

/**
 * is_path - if path not absolute
 * @path: path of function
 *
 * Return: 1 (not absolute) 0 (absolute)
 **/
int is_path(char *path)
{
	if (_strlen(path) >= 2)
	{
		if ((path[0] == '.' && path[1] == '/') || path[0] == '/' ||
			(path[0] == '.' && path[1] == '.' && path[2] == '/'))
			return (1);
	}

	return (0);
}

/**
 * make_path - make path to file from directory and file
 * @path: path to directory
 * @file: file
 * Return: New Path
 **/
char *make_path(char *path, char *file)
{
	char *npath;

	if (path == NULL || file == NULL)
		return (NULL);

	npath = malloc(sizeof(char) *
			(_strlen(path) + _strlen(file) + 2));
	if (!npath)
		return (NULL);

	_strcpy(npath, path);
	npath[_strlen(path)] = '/';
	npath[_strlen(path) + 1] = '\0';
	_strcat(npath, file);

	return (npath);
}

/**
 * path_match - find directory insid PATH
 * that file resides in if any
 * @exec: executable name
 * Return: full path of executable or NULL if it's not found
 **/
char *path_match(char **exec)
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

	while (arr_p[i] != NULL)
	{
		p = make_path(arr_p[i], *exec);
		if (stat(p, &st) == 0)
		{
			free(*exec);
			*exec = p;
			free_tow(arr_p);
			return (p);
		}

		free(p);
		i++;
	}
	free_tow(arr_p);
	return (NULL);
}
