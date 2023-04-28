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
