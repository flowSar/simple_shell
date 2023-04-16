#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
char *concatenate(char *str, int len);

/**
 * main- entry function
 * Return: 0 if success and 1 if fails .
 */

int main(void)
{
	char *command_line = malloc(3);
	ssize_t command_len = 0;
	ssize_t len;

	printf("$");
	len = getline(&command_line, &command_len, stdin);
	command_line = concatenate(command_line, len);

	char *args[] = {NULL};
	char *envp[] = {NULL};

	if (execve(command_line, args, envp) == -1) 
	{
		perror("./shell");
		exit(1);
	}
	free(command_line);
	return (0);
}
/**
 * concatenate -function that concatenate two strings.
 * @str: input.
 * @len : length of str.
 * Return: string .
 */

char *concatenate(char *str, int len)
{
	char *path = "/bin/";
	char *full_path = malloc(5 + len);
	int i = 0, p = 0;

	while (path[i] != '\0')
	{
		full_path[i] = path[i];
		i++;
	}
	p = i;
	i = 0;
	while (str[i + 1] != '\0')
	{

		full_path[p] = str[i];
		i++;
		p++;
	}
	return (full_path);
}
