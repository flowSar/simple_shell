#include <stdio.h>
/**
 * _isEqual- this functio check if two string equal.
 * @str1: string one.
 * @str2: string two.
 * Return: 0 if two equal and 1 if not .
 */
int _isEqual(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}
