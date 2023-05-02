#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include "main.h"

/**
 * sigint_handler- this function handle exit with CTRL^D.
 * @sig: argument number.
 */
void sigint_handler(__attribute__((unused))int sig)
{
	_putchar('\n');
	_exit(0);
}
/**
 * main- entry function.
 * @argc: argument number.
 * @argv: argument list.
 * @envp: environment settings list.
 * Return: 0 if success and 1 if fails .
 */
int main(__attribute__((unused))int argc, char **argv, char **envp)
{
	char **args = NULL;
	LIST *list = NULL;
	char *command = NULL;
	pid_t pid;

	while (1)
	{
		list = execu_prepare(envp);
		if (!list)
			continue;
		args = list->args;
		command = list->command;
		if (list)
			pid = fork();
		if (pid == 0)
		{
			if (execve(concatenate(args[0]), args, envp) == -1)
			{
				_printf(command + 5);
				_printf(": command not found\n");
				free(command);
				exit(0);
			}
		}
		else if (pid == -1)
		{
			exit(0);
		}
		else
		{
			int status = 0;

			waitpid(pid, &status, 0);
			signal(SIGINT, sigint_handler);
			if (status == -1)
			{
				free_memory(list->args);
				perror(argv[0]);
				exit(0);
			}
		}
	}
	return (0);
}
