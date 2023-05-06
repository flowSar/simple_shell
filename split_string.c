#include "main.h"
/**
  * split_By - split string by flag and load it
  * to at list and add NULL at last index of the list
  * like {"ls", "-l", NULL}.
  * @str: input.
  * @flag: flsg.
  * Return: list of strings.
  */
char **split_By(char *str, char flag)
{
	int counter = 0, index = 0, space = -1, chunck_number, row = 0;
	char **args = NULL;
	int i = 0;

	chunck_number = get_chuck_number(str);
	args = malloc((chunck_number + 1) * sizeof(char *));
	if (str == NULL)
		return (0);

	while (str[index] != '\0')
	{
		if (str[index] != flag)
		{
			counter++;
			space = -1;
		}
		if (str[index] == flag || str[index + 1] == '\0')
		{
			space += 1;
			if (space == 0)
			{
				if (str[index + 1] == '\0')
					args[row] = get_chunck(str, i, index + 1);
				else
					args[row] = get_chunck(str, i, index);
				row++;
			}
			counter = 0;
			i = index + 1;
		}
		index++;
	}
	args[row] = NULL;
	free(str);
	return (args);
}
/**
  * get_chuck_number - get number of chuncks in command line
  * @str: command line.
  * Return: return number of chuncks.
  */
int get_chuck_number(char *str)
{
	int word_nm = 0, s = -1, i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			s += 1;
			if (s == 0)
				word_nm += 1;
		}
		else
		{
			s = -1;
		}
		i++;
	}
	return (word_nm);
}

/**
  * get_chunck - function get a piece of string from str
  * from index start to index end.
  * @str: input strig.
  * @start: start from.
  * @end : end.
  * Return: return required piece.
  */
char *get_chunck(char *str, int start, int end)
{
	char *ch = NULL;
	int i = 0, j = start;
	int len = end - start;

	ch = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		ch[i] = str[j];
		i++;
		j++;
	}
	ch[i] = '\0';
	return (ch);
}
