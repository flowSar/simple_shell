#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
  * split_string - splits a string by spaces
  * @input_str: input
  * Return: list of splitted strings
  */
char **split_string(char *input_str)
{
	char **my_list;
	int row = 1, colum = 1, s = -1, i = 0, j = 0, p = 0;
	if (input_str != NULL)
	{
		my_list = malloc(row * sizeof(char *));
		my_list[0] = malloc(colum * sizeof(char));
	}

	while (input_str[p] != '\0')
	{
		if (input_str[p] != ' ')
		{
			my_list[i][j] = input_str[p];
			colum++;
			j++;
			my_list[i] = realloc(my_list[i],colum * sizeof(char));
			s = -1;
		}
		else if (input_str[p] == ' ')
		{
			s += 1;
			if (s == 0)
			{
				my_list[i][j] = '\0';
				row++;
				i++;
				my_list = realloc(my_list, row * sizeof(char *));
				my_list[i] = malloc(sizeof(char));
				j = 0;
			}
		}
		p++;
	}
	return (my_list);
}
