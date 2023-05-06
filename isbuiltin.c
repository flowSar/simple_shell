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
	int i = 0, exit_status = 0;

	if (command == NULL || args == NULL)
		return (0);

	if (_isEqual(command, env) == 0)
	{
		while (envp[i] != NULL)
			printf("%s\n", envp[i++]);
		free_memory(args);
		return (0);
	}
	else if (_isEqual(command, Exit) == 0 && args[1] == NULL)
	{
		free_memory(args);
		exit(0);
	}
	else if (_isEqual(args[0], Exit) == 0 && args[1] != NULL)
	{
		exit_status = atoi(args[1]);
		free_memory(args);
		exit(exit_status);
	}
	return (-1);
}
