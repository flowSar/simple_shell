#include "main.h"


/**
 * _getenv - get env var
 * @name: global variable
 * Return: value of var
 */
char *_getenv(const char *name)
{
	int i, j;
	char *value;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;

				j++;
			}
			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (0);
}


/**
 * append_node - appends a new node at the end of a list_t
 * @head: linked list head
 * @str: ptr of previous head node
 * Return: ptr to new head
 */

list_path *append_node(list_path **head, char *str)
{

	list_path *tmp;
	list_path *new;

	new = malloc(sizeof(list_path));

	if (!new || !str)
	{
		return (NULL);
	}

	new->dir = str;

	new->p = '\0';
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;

		while (tmp->p)
		{

			tmp = tmp->p;
		}

		tmp->p = new;
	}

	return (*head);
}


/**
 * path_list - creates a list for path directories
 * @path: path value
 * Return: ptr to list head
 */
list_path *path_list(char *path)
{
	list_path *head = '\0';
	char *token;
	char *var_path = _strdup(path);

	token = strtok(var_path, ":");
	while (token)
	{
		head = append_node(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/**
 * find_pathname - finds the path of filename
 * @filename: name of file
 * @head: head of list of path directories
 * Return: path of filename or NULL if not found
 */
char *find_pathname(char *filename, list_path *head)
{
	struct stat st;
	char *str;

	list_path *tmp = head;

	while (tmp)
	{

		str = strcat_all(tmp->dir, "/", filename);
		if (stat(str, &st) == 0)
		{
			return (str);
		}
		free(str);
		tmp = tmp->p;
	}

	return (NULL);
}

/**
 * free_list - frees list_t
 *@head: ptr to list head
 */
void free_list(list_path *head)
{
	list_path *tmp;

	while (head)
	{
		tmp = head->p;
		free(head->dir);
		free(head);
		head = tmp;
	}

}
