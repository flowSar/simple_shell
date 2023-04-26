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

int main(int argc, __attribute__((unused))char **argv, char **envp)
{
	char *command_line;
	int len = 0, res;
	pid_t pid;

	while (1)
	{
		printf("$");
		fflush(stdout);
		len = _getline(&command_line, 1024 + argc);
		if (len == 1)
			continue;
		if (len > 1)
			pid = fork();
		if (pid == 0)
		{
			res = execute(command_line, len, pid, envp);
			if (res == -1)
				break;
		}
		else if (pid == -1)
		{
			printf("fork failed \n");
			exit(1);
		}
		else
		{
			int status = 0;

			if (len == 0)
				exit(1);
			waitpid(pid, &status, 0);
			if (status == -1)
			{
				perror("./shell");
				exit(1);
			}
		}
	}
	return (0);
}
