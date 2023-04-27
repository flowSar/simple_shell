#include "main.h"
/**
  * is_builtin -  checks for builin commands like env and exit
  * @prog: command to be executed
  * @envp: envp passed from the OS
  * @parent_pid: main process PID
  * Return: 1 if command is builtin 0 otherwise
  */
int is_builtin(char *prog, char **envp, pid_t parent_pid)
{
	char *exit_call = "exit";
	char *env = "env";

	if (strcmp(prog, exit_call) == 0)
	{
		kill(parent_pid, SIGINT);
		return (1);
	}

	else if (strcmp(prog, env) == 0)
	{
		while (envp)
		{
			printf("%s\n", *envp);
			envp++;
		}

		return (1);

	}

	else
		return (0);
}
