#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include "main.h"

/**
 * remove_new_Line- this function removes new line at the end of command line.
 * @str: command line.
 * Return: new string after removing \n or NULL if it fail.
 */
char *remove_new_Line(char *str)
{
	int len, i = 0;
	char *new_str = NULL;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	new_str = malloc(len * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
	new_str[i] = '\0';
	return (new_str);
}
