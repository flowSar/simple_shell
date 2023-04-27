#include "main.h"

/**
 * exit_handler - exits the shel with status n
 * @argv: argv
 */
void exit_handler(char **argv)
{
	int i, n;

	if (argv[1])
	{
		n = _atoi(argv[1]);
		if (n <= -1)
			n = 2;
		free_argv(argv);
		exit(n);
	}
	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	exit(0);
}

/**
 * _atoi - the same as atoi
 *@s: ptr to char list
 *Return: integer of input string
 */
int _atoi(char *s)
{
	int i, integer, sign = 1;

	i = 0;
	integer = 0;
	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
	{
		if (s[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (integer);
}

/**
 * env - env builtin command
 * @argv: argv
 */
void env(char **argv __attribute__ ((unused)))
{

	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}

}

/**
 * _setenv - sets env var if found and create it id not found
 * @argv: argv
 */
void _setenv(char **argv)
{
	int i, j, k;

	if (!argv[1] || !argv[2])
	{
		perror(_getenv("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (argv[1][j] == environ[i][j])
		{
			while (argv[1][j])
			{
				if (argv[1][j] != environ[i][j])
				{
					break;
				}
				j++;
			}
			if (argv[1][j] == '\0')
			{
				k = 0;
				while (argv[2][k])
				{
					environ[i][j + 1 + k] = argv[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{

		environ[i] = strcat_all(argv[1], "=", argv[2]);
		environ[i + 1] = '\0';

	}
}

/**
 * _unsetenv - Removes env var
 * @argv: argv
 */
void _unsetenv(char **argv)
{
	int i, j;

	if (!argv[1])
	{
		perror(_getenv("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (argv[1][j] == environ[i][j])
		{
			while (argv[1][j])
			{
				if (argv[1][j] != environ[i][j])
					break;

				j++;
			}
			if (argv[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}

