#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <string.h>
#include <stdlib.h>
#include "strtow.h"

char *strnon(char *str)
{
	int l, i = 0, n = 0, j = 0;
	char *s;

	if (str == NULL)
		return (NULL);
	l = strlen(str);
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	s = malloc(sizeof(char) * ((l + 1) - n));

	i = 0; j = 0;

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

void fork_n_run(char **av)
{

	pid_t my_pid, child;
	int wstatus;

	if (child = fork(), child == -1)
		printf("\nss: %s:  Process cannot be started\n", av[0]);

	if (child == 0)
	{
		my_pid = execve(av[0], av, NULL);

		if (my_pid == -1)
		{
			printf("\nss: %s:  cannot be executed\n", av[0]);
			exit(1);

		}
	}

	else
		wait(&wstatus);
}

int main (void)
{
	char *s = NULL, **av;
	size_t count;

	while (1)
	{
		fputs("$ ", stdout);
		if (getline(&s, &count, stdin) == EOF)
		{
			puts("\nexit");
			free(s);
			exit(1);
		}

		if (strcmp(s, "\n"))
		{
			s = strnon(s);
			av = strtow(s, ' ');

			free(s);
			s = NULL;

			fork_n_run(av);
			free_tow(av);
		}
		else
		{
			free(s);
			s = NULL;
		}

	}

	return (0);
}
