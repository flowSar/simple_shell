#include "main.h"


/**
 * main- entry function.
 * @argc: argument number.
 * @argv: argument list.
 * @envp: environment settings list.
 * Return: 0 if success and 1 if fails .
 */
int main(__attribute__((unused))int argc, char **argv, char **envp)
{
	char **args = NULL;
	char *ch = NULL;

	while (1)
	{
		signal(SIGINT, sigint_handler);
		args = execu_prepare(envp);

		if (args == NULL)
			continue;
		ch = _strdup(args[0]);
		execute(args, ch, argv, envp);
		free(ch);
		free_memory(args);
	}
	return (0);
}
