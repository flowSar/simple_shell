#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * execu_prepare -this function prepere command line for execute.
 * @envp:environment.
 * Return: return command line and its argument in a list.
 */

char **execu_prepare(char **envp)
{
	char *command_line;
	char **args;
	size_t len;
	int status;

	write(STDIN_FILENO, "$ ", 2);
	fflush(stdout);
	len = _getline(&command_line, 1024);
	if (len == 0)
		exit(0);
	command_line = remove_new_Line(command_line);
	args = split_string(command_line);
	status = isbuildin(command_line, args, envp);
	if (status == -1 && len != 1)
	{
		free(command_line);
		if (args == NULL)
			return (NULL);
		return (args);
	}
	else if (status != -1)
	{
		free(command_line);
		free_memory(args);
		exit(status);
	}
	else if (status == -1 && len == 1)
	{
		free(command_line);
		free_memory(args);
		return (NULL);
	}
	return (NULL);
}
