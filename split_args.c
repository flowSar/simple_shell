#include "main.h"

/**
  * split_args - splits a string by ' '
  * @input_str: string to be splitted
  * Return: a douuble pointer to strings separated
  */
char **split_args(char *input_str)
{

	int index = 0;

	char *tok;

	char *dup;

	char **args_list = NULL;  /*pointer to list of strings (dynamic lists)*/

	char *argument = malloc(strlen(input_str) + 1); /*string entry for args_list*/

	strcpy(argument, input_str);

	tok = strtok(argument, " "); /*initial call for strtok*/

	while (tok != NULL)
	{

		args_list = realloc(args_list, sizeof(char *) * (index + 1));

		dup = malloc(strlen(tok) + 1);

		strcpy(dup, tok);

		args_list[index++] = dup;

		tok = strtok(NULL, " ");
	}

	args_list = realloc(args_list, sizeof(char *) * (index + 1)); /* +1 for '\0'*/

	args_list[index] = NULL;

	free(argument);

	return (args_list);
}
