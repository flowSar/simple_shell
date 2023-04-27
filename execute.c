#include "main.h"


/**
 * splits_string - splits a string into tokens
 * @str: input
 * @delim: delimiter
 * Return: ptr to list of tokens
 */

char **splits_string(char *str, const char *delim)
{
	int i, count;
	char **array;
	char *token;
	char *tmp;

	tmp = malloc(_strlen(str) + 1);
	if (tmp == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';

	token = strtok(tmp, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(token);

	i = 1;
	count = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = _realloc(array, (sizeof(char *) * (count - 1)), (sizeof(char *) * count));
		array[i] = _strdup(token);
		i++;
		count++;
	}
	free(tmp);
	return (array);
}

/**
 * execute - executes a command
 * @argv: argv
 */

void execute(char **argv)
{

	int i, status;

	if (!argv || !argv[0])
		return;
	i = fork();
	if (i == -1)
	{
		perror(_getenv("_"));
	}
	if (i == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}

/**
 * _realloc - the same as realloc
 * @ptr: last ptr
 * @p_size: last size of last ptr
 * @n_size: new size for ptr
 * Return: resized ptr
 */

void *_realloc(void *ptr, unsigned int p_size, unsigned int n_size)
{
	char *new;
	char *last;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(n_size));

	if (n_size == p_size)
		return (ptr);

	if (n_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(n_size);
	last = ptr;
	if (new == NULL)
		return (NULL);

	if (n_size > p_size)
	{
		for (i = 0; i < p_size; i++)
			new[i] = last[i];
		free(ptr);
		for (i = p_size; i < n_size; i++)
			new[i] = '\0';
	}
	if (n_size < p_size)
	{
		for (i = 0; i < n_size; i++)
			new[i] = last[i];
		free(ptr);
	}
	return (new);
}

/**
 * free_argv - frees argv
 *@argv: argv
 */

void free_argv(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
}
