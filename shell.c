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
	char *args[] = {concatenate(NULL, 0),NULL};
	char *envp[] = {NULL};
	unsigned long int command_len = 0;
	ssize_t len;
	pid_t pid = fork();

	if (pid == 0)
	{
		printf("$");
		len = getline(&command_line, &command_len, stdin);
		command_line = concatenate(command_line, len);
		if (execve(command_line, args, envp) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	else
	{
		int status = 0;

		waitpid(pid, &status, 0);

		if (execve("./shell", args, envp) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	free(command_line);
	return (0);
}
