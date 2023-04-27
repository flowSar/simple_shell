#include "main.h"

/**
  * allocate_string - reallocates a oversized buffer to a string
  *	execve doesn't accept oversized buffer + non space is wasted :)
  * @c: string (oversized buffer with \0
  * Return: string of size len(c)
  */
char *allocate_string(char *c)
{
	int len = strlen(c);

	int i = 0;

	char *tmp = malloc(len - 1);

	while (c[i])
	{
		tmp[i] = c[i];
		i++;
	}

	tmp[i - 1] = '\0';

	return (tmp);
}
