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
