#include "main.h"

#define INFINITE 1


/**
 * main - main loop of shell
 *
 * Return: 0 success, other otherwise
 **/
int main(void)
{
	char *s = NULL;
	size_t count = 0;
	ssize_t gt = 0;

	while (isatty(STDIN_FILENO) == 0)
	{
		gt = getline(&s, &count, stdin);
		if (gt == EOF)
		{
			free(s);
			exit(0);
		}

		if (_strcmp(s, "\n"))
		{
			execute_line(s);
			s = NULL;
		}
	}
	if (isatty(STDIN_FILENO) == 0)
		return (0);

	while (INFINITE)
	{
		write(STDOUT_FILENO, "$ ", 2);
		gt = getline(&s, &count, stdin);

		if (gt == EOF)
		{
			write(STDOUT_FILENO, "\nexit\n", 6);
			free(s);
			exit(0);
		}

		if (_strcmp(s, "\n"))
		{
			execute_line(s);
			s = NULL;
		}

		else
		{
			free(s);
			s = NULL;
		}
	}

	return (0);
}
