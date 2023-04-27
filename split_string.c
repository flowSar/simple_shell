#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
/**
  * split_string - splits string by ' ' and load it
  * at list and add NULL at last index of the list
  * like {"ls", "-l", NULL}.
  * @input_str: input.
  * Return: list of strings.
  */
char **split_string(char *input_str)
{
	char **m_list;
	int row = 1, colum = 1, s = -1, i = 0, j = 0, p = 0;

	if (input_str != NULL)
	{
		m_list = malloc(row * sizeof(char *));
		m_list[0] = malloc(colum * sizeof(char));
	}

	while (input_str[p] != '\0')
	{
		if (input_str[p] != ' ')
		{
			m_list[i][j] = input_str[p];
			colum++;
			j++;
			m_list[i] = realloc(m_list[i], colum * sizeof(char));
			s = -1;
		}
		else if (input_str[p] == ' ')
		{
			s += 1;
			if (s == 0)
			{
				m_list[i][j] = '\0';
				row++;
				i++;
				m_list = realloc(m_list, row * sizeof(char *));
				m_list[i] = malloc(sizeof(char));
				j = 0;
			}
		}
		p++;
	}
	row++;
	m_list = realloc(m_list, row * sizeof(char *));
	m_list[i + 1] = malloc(sizeof(char));
	m_list[i + 1] = NULL;
	return (m_list);
}
