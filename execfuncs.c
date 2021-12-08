#include "main.h"
#include "builtins.h"
#include "strtow.h"
#include <sys/wait.h>

char **lines;

/**
* err_out - print commont shell error
* @name: name of component producing the error
* @err: string of error
*
**/
void err_out(char *name, char *err)
{
	write(STDOUT_FILENO, "hsh: ", 5);
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, err, _strlen(err));
}

/**
* exec_bltn - execute builtin shell functions
* @av: array of arguments
* Return: (1) success (2) error
*
**/
int exec_bltn(char **av)
{
	bltn bltns[] = {{"cd", fcd}, {"exit", fexit},
		{"env", fenv}, {NULL, NULL}};
	int i = 0;

	while (bltns[i].s)
	{
		if (_strcmp(bltns[i].s, av[0]) == 0)
			return (bltns[i].f(av));
		i++;
	}

	return (0);
}

/**
* run_av - fork and run program with parameters
*
* @av: array of strings of program and it's pramaters
*
* Return: return value of child process
**/
int run_av(char **av)
{

	pid_t my_pid, child;
	int wstatus;

	child = fork();

	if (child == -1)
		perror("hsh");

	if (child == 0)
	{
		my_pid = execve(av[0], av, environ);
		if (my_pid == -1)
		exit(1);
	}

	else
		wait(&wstatus);

	return (WEXITSTATUS(wstatus));
}

/**
* execute_line - execute line of commands
* @line: line
**/
void execute_line(char *line)
{
	char **av, *p;
	int i = 0;

	line[_strlen(line) - 1] = '\0';
	lines = strtow(line, ';');
	free(line);
	while (lines && lines[i])
	{
		av = strtow(lines[i], ' ');
		free(lines[i]);
		i++;
		if (av != NULL)
		{
			exec_bltn(av);

			p = _strdup(av[0]);

			if (is_path(av[0]))
			{
				if (run_av(av))
					perror(p);

			}

			else if (path_match(&av[0]))
			{
				if (run_av(av))
					perror(p);
			}

			else
				err_out(av[0], "not found\n");

			free(p);
			free_tow(av);
		}
	}
	free(lines);
}
