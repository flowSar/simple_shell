#include "main.h"

/**
 * execu_prepare -this function prepere command line for execute.
 * @envp:environment.
 * Return: return command line and its argument in a list.
 */

char **execu_prepare(char **envp)
{
	char *command_line = NULL;
	char **args = NULL;
	size_t len = 0, command_len = 0;
	int status = 0;

	write(STDIN_FILENO, "$ ", 2);
	fflush(stdout);
	len = getline(&command_line, &command_len, stdin);
	if (len == 1)
	{
		return (NULL);
	}
	if ((int)len == -1)
	{
		free_memory(args);
		exit(0);
	}
	command_line = clean_command(command_line);
	args = split_By(command_line, ' ');
	status = isbuildin(args[0], args, envp);
	if (status == -1 && len != 1)
	{
		if (args == NULL)
			return (NULL);
		return (args);
	}
	return (NULL);
}

/**
 * execute -execute command line.
 * @cmd:command line.
 * @envp: environment variable.
 * @argv: argument.
 * @ch: command.
 * Return: void.
 */

void execute(char **cmd, char *ch, char **argv, char **envp)
{
	pid_t pid;
	int st = 0;

	if (cmd)
		pid = fork();
	if (pid == 0)
	{
		if (execve(concatenate(cmd[0]), cmd, envp) == -1)
		{
			_printf(ch);
			_printf(": command not found\n");
			free(ch);
			exit(0);
		}
	}
	else if (pid == -1)
	{
		free_memory(cmd);
		exit(0);
	}

	waitpid(pid, &st, 0);
	if (st == -1)
	{
		perror(argv[0]);
		exit(0);
	}
}

/**
 * sigint_handler- this function handle exit with CTRL^D.
 * @sig: argument number.
 */
void sigint_handler(__attribute__((unused))int sig)
{
	_printf("\n$ ");
}
