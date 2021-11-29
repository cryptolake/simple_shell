#include "main.h"

#define INFINITE 1

/**
 * strnon - remove newline from string
 * @str: string
 *
 * Return: string without newline
 **/
char *strnon(char *str)
{
	int l, i = 0, n = 0, j = 0;
	char *s;

	if (str == NULL)
		return (NULL);
	l = _strlen(str);
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	s = malloc(sizeof(char) * ((l + 1) - n));

	i = 0;
	j = 0;

	while (i <= l)
	{
		if (str[i] != '\n')
		{
			s[j] = str[i];
			j++;
		}
		i++;
	}
	free(str);

	return (s);
}

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
	char *p;

	line = strnon(line);
	av = strtow(line, " ");

	if (av == NULL)
		free(line);

	else
	{
		free(line);

		p = path_handle(av[0]);
		/* printf("\np = %s\n",p); */
		if (p)
		{
			free(av[0]);
			av[0] = p;
			run_av(av);
			free_tow(av);
		}

		else
		{
			printf("\nfile not found.\n");
			free_tow(av);

		}

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
