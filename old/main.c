#include "main.h"

/**
 * signal_handler - checks if Ctrl-c
 * @signal_number: signal number
 */
void signal_handler(int signal_number)
{
	if (signal_number == SIGINT)
	{
		_puts("\n$ ");
	}
}

/**
* end_of_file - handles end of file
* @len: getline function return
* @buffer: chars buffer
 */
void end_of_file(int len, char *buffer)
{
	(void)buffer;

	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buffer);
		}
		exit(0);
	}
}
/**
  * is_terminal - verif if open fd is terminal
  */

void is_terminal(void)
{
	if (isatty(STDIN_FILENO))
	{
		_puts("$ ");
	}
}
/**
 * main - code entry point
 * Return: 0 on success otherwise exit code
 */

int main(void)
{
	ssize_t len = 0; 
	size_t size = 0;
	char *buffer = NULL, *val, *path, **argv;
	list_path *string_end = '\0';
	void (*f)(char **);

	signal(SIGINT, signal_handler);
	while (len != EOF)
	{
		is_terminal();
		len = getline(&buffer, &size, stdin);
		end_of_file(len, buffer);
		argv = splits_string(buffer, " \n");
		if (!argv || !argv[0])
			execute(argv);
		else
		{
			val = _getenv("PATH");
			string_end = path_list(val);
			path = find_pathname(argv[0], string_end);
			f = is_builtin(argv);
			if (f)
			{
				free(buffer);
				f(argv);
			}
			else if (!path)
				execute(argv);
			else if (path)
			{
				free(argv[0]);
				argv[0] = path;
				execute(argv);
			}
		}
	}
	free_list(string_end);
	free_argv(argv);
	free(buffer);
	return (0);
}
