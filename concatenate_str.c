#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * concatenate -function that concatenate two strings.
 * @str: input string.
 * Return: string .
 */
char *concatenate(char *str)
{
	char *path = "/bin/";
	int len = 0;
	char *full_path = NULL;
	int i = 0, p = 0;

	if (str)
		len = _strlen(str);
	full_path = malloc(len + len);
	while (path[i] != '\0')
	{
		full_path[i] = path[i];
		i++;
	}
	p = i;
	i = 0;
	if (str == NULL)
		return (full_path);
	while (str[i] != '\0')
	{
		if (full_path[i] != str[i])
		{
			full_path[p] = str[i];
			p++;
		}
		i++;
	}
	free(str);
	return (full_path);
}
