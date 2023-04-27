#include "main.h"

/**
 * _strdup - copies a str to new place in memory
 * @str: string to be copied
 * Return: ptr to created string
 */
char *_strdup(char *str)
{
	int i, l;
	char *new;

	if (!str)
	{
		return (NULL);
	}
	for (l = 0; str[l] != '\0';)
	{
		l++;
	}
	new = malloc(sizeof(char) * l + 1);
	if (!new)
	{
		return (NULL);
	}
	for (i = 0; i < l; i++)
	{
		new[i] = str[i];
	}
	new[l] = str[l];
	return (new);
}

/**
 * strcat_all - concats 3 strings in a memory loc
 * @name: str1
 * @delim: delimeter
 * @val: value
 * Return: ptr to the new string
 */
char *strcat_all(char *name, char *delim, char *val)
{
	char *result;
	int len1, len2, len3, i, k;

	len1 = _strlen(name);
	len2 = _strlen(delim);
	len3 = _strlen(val);

	result = malloc(len1 + len2 + len3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; delim[i]; i++)
		result[k + i] = delim[i];
	k = k + i;

	for (i = 0; val[i]; i++)
		result[k + i] = val[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

/**
 * _strlen - the same as strlen
 * @s: ptr to char list
 * Return: len of s
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _putchar - writes the char c to stdout
 * @c: The char to be printed
 * Return: On success 1, -1 and err
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - the same as puts
 * @str: ptr to str
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
