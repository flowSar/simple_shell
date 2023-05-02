#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * execu_prepare -this function prepere command line for execute.
 * @envp:environment.
 * Return: return command line and its argument in a list.
 */

LIST *execu_prepare(char **envp)
{
	char *command_line = NULL;
	char **args = NULL;
	LIST list;
	LIST *arg_list = &list;
	size_t len = 0, command_len;
	int status = 0;

	write(STDIN_FILENO, "$ ", 2);
	fflush(stdout);
	len = getline(&command_line, &command_len, stdin);
	if (len == 0)
		exit(0);
	if (len == 1)
		return (NULL);
	if ((int)len == -1)
		exit(0);
	command_line = clean_command(command_line);
	args = split_By(command_line, ' ');
	arg_list->args = args;
	arg_list->command = command_line;
	status = isbuildin(command_line, args, envp);
	if (status == -1 && len != 1)
	{
		free(command_line);
		if (args == NULL)
			return (NULL);
		return (arg_list);
	}
	else if (status == -1 && len == 1)
	{
		free(command_line);
		free_memory(args);
		return (NULL);
	}
	return (NULL);
}
