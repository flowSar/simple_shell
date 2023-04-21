#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

extern char **environ;

void execute(char *command_line, int len, pid_t pid)
{
	char **args_list;
	char *program_exit = "exit";
	char *env_command = "env";
	char **envp = environ;
	int i = 0;

	command_line = remove_new_Line(command_line);
	if (strcmp(command_line, program_exit) == 0)
	{
		kill(pid, SIGTERM);
		exit(0);
	}
	else if (strcmp(command_line, env_command) == 0)
	{
		while (envp[i] != NULL)
		{
			printf("%s\n", envp[i]);
			i++;
		}
	}
	else
	{
		args_list = split_string(command_line);
		if (execve(concatenate(args_list[0], len), args_list, NULL) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
}
