#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

/**
 * main- entry function.
 * Return: 0 if success and 1 if fails .
 */

int main(void)
{
	char *command_line = malloc(3);
	char **args_list;
	char *envp[] = {NULL};
	unsigned long int command_len = 0;
	ssize_t len;
	pid_t parent_pid = getpid(), pid;

	while (1)
	{
		printf("$");
		len = getline(&command_line, &command_len, stdin);
		if (len > 1)
			pid = fork();

		if (pid == 0)
			execute(command_line, len, parent_pid);
		else if (pid == -1)
		{
			printf("fork failed \n");
		}
		else
		{
			int status = 0;

			waitpid(pid, &status, 0);
			if (status == -1)
			{
				perror("./shell");
				exit(1);
			}
		}
	}
	free(command_line);
	return (0);
}
