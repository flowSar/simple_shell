#include "main.h"

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

/**
  * _putchar - clonning putchar function.
  * @c: char.
  * Return: return -1 if it faild .
  */
int _putchar(char c)
{
	return (write(0, &c, 1));
}
/**
  * _printf - print onle one string.
  * @str: char.
  * Return: return number of char .
  */
int _printf(char *str)
{
	int i = 0, len = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
		len++;
	}
	return (len);
}
/**
  * _strdup - duplicate a string.
  * @str: string.
  * Return: return duplicated string .
  */
char *_strdup(char *str)
{
	int len = 0, i = 0;
	char *new_ = NULL;

	if (!str)
		return (NULL);

	len = _strlen(str);
	new_ = malloc((len + 1) * sizeof(char));
	if (!new_)
		return (NULL);

	while (str[i] != '\0')
	{
		new_[i] = str[i];
		i++;
	}
	new_[i] = '\0';
	return (new_);
}
