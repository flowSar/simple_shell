#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

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
	pid_t pid;

	while (1)
	{
		args = execu_prepare(envp);
		if (args)
			pid = fork();
		if (pid == 0)
		{
			if (execve(concatenate(args[0]), args, envp) == -1)
			{
				perror(argv[0]);
				exit(1);
			}
		}
		else if (pid == -1)
		{
			exit(1);
		}
		else
		{
			int status = 0;

			waitpid(pid, &status, 0);
			if (status == -1)
			{
				perror(argv[0]);
				exit(1);
			}
		}
	}
	return (0);
}
