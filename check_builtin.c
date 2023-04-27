#include "main.h"

/**
* is_builtin - checks if command is builtin
* @argv: argv
* Return: pointer to funct that takes argv
*/
void(*is_builtin(char **argv))(char **argv)
{
	int i, j;
	builtins myBuiltins[] = {
		{"exit", exit_handler},
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; myBuiltins[i].name; i++)
	{
		j = 0;
		if (myBuiltins[i].name[j] == argv[0][j])
		{
			for (j = 0; argv[0][j]; j++)
			{
				if (myBuiltins[i].name[j] != argv[0][j])
					break;
			}
			if (!argv[0][j])
				return (myBuiltins[i].func);
		}
	}
	return (0);
}

