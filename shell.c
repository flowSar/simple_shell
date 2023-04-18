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

	while (1)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			printf("$");
			len = getline(&command_line, &command_len, stdin);
			command_line = remove_new_Line(command_line);
			args_list = split_string(command_line);
			if (execve(concatenate(args_list[0], len), args_list, envp) == -1)
			{
				perror("./shell");
				exit(1);
			}
		}
		else if (pid == -1)
		{
			printf("shell closed\n");
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
	return (0);
}
