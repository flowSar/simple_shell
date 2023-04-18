#include <stdio.h>
#include <stdlib.h>

/**
 * concatenate -function that concatenate two strings.
 * @str: input string.
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
	if (str == NULL)
		return(full_path);
	while (str[i + 1] != '\0')
	{
		full_path[p] = str[i];
		i++;
		p++;
	}
	return (full_path);
}
