#include <stdio.h>
#include <stdlib.h>

/**
 * concat -strcat but doesn't replace vars
 * @str: input str
 * @len: len of str
 * Return: concatenated string
 */
char *concat(char *str, int len)
{
	char *path = "/bin/";
	char *absolute_path = malloc(5 + len);
	int i = 0, p = 0;

	while (path[i] != '\0')
	{
		absolute_path[i] = path[i];
		i++;
	}
	p = i;
	i = 0;
	if (str == NULL)
		return(absolute_path);
	while (str[i + 1] != '\0')
	{
		absolute_path[p] = str[i];
		i++;
		p++;
	}
	return (absolute_path);
}
