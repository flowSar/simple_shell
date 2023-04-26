#include <stddef.h>

/**
  * _strlen - get length of a string.
  * @str: string input.
  * Return: return length.
  */
int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (len);

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
  * _strcpy - copy string from pointer to another.
  * @str1: pointer destination.
  * @str2: source.
  * Return: return destination pointer.
  */

char *_strcpy(char *str1, char *str2)
{
	int idx = 0;

	if (str1 == NULL && str2 != NULL)
		return (str2);
	if (str2 == NULL && str1 != NULL)
		return (str1);
	if (str1 == NULL && str2 == NULL)
		return (NULL);

	while (str2[idx] != '\0')
	{
		str1[idx] = str2[idx];
		idx++;
	}
	return (str1);
}
