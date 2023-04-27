#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include "main.h"
/**
  * execute - replace new process if commandd line doesn't equal
  * exit or env . terminat the process if command = exit.
  * and get enironment setting if command = env.
  * @command_line: input.
  * @len: length,
  * @pid: process id.
  * @envp : environment.
  * Return: 1 if it fail and 0 if it success.
  */

int execute(char *command_line, int len, pid_t pid, char **envp, char *pname)
{
	char **args_list = NULL;
	char *program_exit = "exit";
	char *env_command = "env";
	int i = 0;

	command_line = remove_new_Line(command_line);
	args_list = split_string(command_line);
	if (command_line == NULL)
		return (1);

	if (_isEqual(command_line, program_exit) == 0)
	{
		free(command_line);
		free_memory(args_list);
		kill(pid, SIGINT);
		return (-1);
	}
	else if (_isEqual(command_line, env_command) == 0)
	{
		while (envp[i] != NULL)
		{
			printf("%s\n", envp[i]);
			i++;
		}
		free(command_line);
		free_memory(args_list);
		return (0);
	}
	else
	{
		free(command_line);
		if (execve(concatenate(args_list[0], len), args_list, NULL) == -1)
		{
			perror(pname);
			exit(1);
		}
		return (0);
	}
	return (0);
}
