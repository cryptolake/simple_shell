#include "main.h"
#include <signal.h>
#define INFINITE 1

/**
 * shell_loop - main shell loop
 * @interactive: do the loop in interactive mode or not
 **/
void shell_loop(int interactive)
{
	char *line = NULL;
	size_t count = 0;
	ssize_t gt = 0;

	while (INFINITE)
	{
		if (interactive)
			write(STDOUT_FILENO, "$ ", 2);
		gt = getline(&line, &count, stdin);
		if (gt == EOF)
		{
			free(line);
			exit(0);
		}
		if (_strcmp(line, "\n"))
		{
			execute_line(line);
			line = NULL;
		}

	}

}

/**
 * main - main function to call the loop
 *
 * Return: 0 success, other otherwise
 **/
int main(void)
{

	if (isatty(STDIN_FILENO) == 0)
		shell_loop(0);

	else
		shell_loop(1);

	return (0);
}
