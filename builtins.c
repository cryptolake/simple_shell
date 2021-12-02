#include "main.h"
#include "strtow.h"
#include <stdio.h>
#include <unistd.h>

int fexit(char **av)
{
	int status;

	write(STDOUT_FILENO, "exit\n", 5);

	if (len_tow(av) > 2)
	{
		err_out("exit", "too many arguments\n");
		return (2);
	}

	if (av[1] == NULL)
	{
		exit(1);
	}

	else
	{
		status = _atoi(av[1]);
		exit(status);
	}

	return (2);
}

int fenv(char **av)
{
	extern char **environ;
	int i = 0;

	if (len_tow(av) > 1)
	{
		err_out("env", "too many arguments\n");
		return (2);
	}

	while (environ[i])
	{
		if (write(STDOUT_FILENO, environ[i], _strlen(environ[i])) == -1)
		{
			perror("env");
			return (2);
		}

		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
	return (1);
}

int fcd(char **av)
{
	if (len_tow(av) > 2)
	{
		err_out("cd", "too many arguments\n");
		return (2);
	}

	if (av[1] == NULL)
	{
		if (chdir(_getenv("HOME")) == -1)
		{
			perror("cd");
			return (2);
		}
	}
	else
	{
		if (chdir(av[1]) == -1)
		{
			perror("cd");
			return (2);
		}
	}
	return (1);
}
