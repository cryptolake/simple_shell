#include "main.h"

#define INFINITE 1

/**
 * run_av - fork and run program with parameters
 *
 * @av: array of strings of program and it's pramaters
 **/
void run_av(char **av)
{

	pid_t my_pid, child;
	int wstatus;

	child = fork();

	if (child == -1)
		perror("hsh");

	if (child == 0)
	{
		my_pid = execve(av[0], av, NULL);

		if (my_pid == -1)
		{
			perror(av[0]);
			free_tow(av);
			exit(1);
		}
	}

	else
		wait(&wstatus);
}

/**
 *
 *
 **/
void execute_line(char *line)
{
	char **av;

	line = strnon(line);
	av = strtow(line, " ");

	if (av == NULL)
		free(line);

	else
	{
		free(line);
		run_av(av);
		free_tow(av);
	}
}


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
