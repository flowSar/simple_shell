#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * isbuildin -this function check if command line a builtin command.
 * @command:command.
 * @args: command argumen.
 * @envp : environment variable.
 * Return: 0 if buildtin command and -1 if not.
 */

int isbuildin(char *command, char **args, char **envp)
{
	char *env = "env";
	char *Exit = "exit";
	int i = 0;

	if (_isEqual(command, env) == 0)
	{
		while (envp[i] != NULL)
		{
			printf("%s\n", envp[i]);
			i++;
		}
		return (0);
	}
	else if (_isEqual(command, Exit) == 0)
	{
		exit(0);
		return (0);
	}
	else if (_isEqual(args[0], Exit) == 0)
	{
		if (args[1] != NULL || _strlen(args[1]) < 2)
			exit(atoi(args[1]));
	}
	return (-1);
}