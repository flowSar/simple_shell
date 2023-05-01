#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * free_memory- this function used to free memory of list.
 * @list: aloccated memory to where will store readed data.
 */
void free_memory(char **list)
{
	int i = 0;

	if (list != NULL)
	{
		while (list[i] != NULL)
		{
			free(list[i]);
			i++;
		}
		free(list);
	}
}

/**
 * _realloc- mimic realloc function.
 * @str: old memory location.
 * @new_size: size of a new alocated memory.
 * Return: the new alocated memory.
 */

void *_realloc(void *str, int new_size)
{
	char *ptr;
	int ptr_len = _strlen((char *)str);

	if (ptr_len == new_size)
		return (str);
	if (new_size == 0)
	{
		free(str);
		return (NULL);
	}
	if (str == NULL)
		return (malloc(new_size));

	ptr = malloc(new_size);
	ptr = _strcpy(ptr, str);
	free(str);
	return (ptr);
}
