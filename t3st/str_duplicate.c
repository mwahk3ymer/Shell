#include "main.h"

/**
 * _strdup - uplicate string
 * @str: String to duplicate.
 * Return: Pointer to duplicated string in allocated memory
 */

char *_strdup(char *str)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL)
	return (NULL);

	while (str[len])
	len++;
	len++;
	duplicate_str = malloc(sizeof(char) * len);
	if (duplicate_str == NULL)
	return (NULL);
	for (i = 0; i < len; i++)
	{
	duplicate_str[i] = str[i];
	}

	return (duplicate_str);
}
