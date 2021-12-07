#include "main.h"
#include "builtins.h"
#include "strtow.h"

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
 * execute_line - execute line of commands
 * @line: line
 **/
void execute_line(char *line)
{
	char **av;

	/* remove \n from line */
	line[_strlen(line) - 1] = '\0';
	av = strtow(line, ' ');
	free(line);

	if (av != NULL)
	{
		if (exec_bltn(av))
			free_tow(av);

		else if (is_dir(av[0]))
		{
			err_out(av[0], "Is a directory\n");
			free_tow(av);
		}


		else if (is_path(av[0]))
		{
			run_av(av);
			free_tow(av);
		}


		else if (path_match(&av[0]))
		{
			run_av(av);
			free_tow(av);

		}

		else
		{
			err_out(av[0], "command not found\n");
			free_tow(av);
		}
	}
}