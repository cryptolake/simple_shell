#include "main.h"
#include <signal.h>

/**
 * main - main loop of shell
 *
 * Return: 0 success, other otherwise
 **/
int main(void)
{
	char *line = NULL;
	size_t count = 0;
	ssize_t gt = 0;

	while (isatty(STDIN_FILENO) == 0 && gt != EOF)
	{
		gt = getline(&line, &count, stdin);

		if (_strcmp(line, "\n"))
		{
			execute_line(line);
			line = NULL;
		}
	}

	while (gt != EOF)
	{
		write(STDOUT_FILENO, "$ ", 2);
		gt = getline(&line, &count, stdin);

		if (gt != EOF && _strcmp(line, "\n"))
		{
			execute_line(line);
			line = NULL;
		}
	}

	if (gt == EOF)
	{
		free(line);
		line = NULL;
		write(STDOUT_FILENO, "\nexit\n", 6);
	}

	return (0);
}
