#include "main.h"
/**
 * _string_tokenization - Mimics strtok,tokenizes a string and turn to array.
 * @sourc: String from getline.
 * @delim: " ";
 * Return: Individual token in array format.
 */

char *_string_tokenization(char *sourc, const char *delim)
{
	static char *s;
	static unsigned int i;
	char *result = NULL;
	int space = 0;

	if (sourc)
	{
		p = sourc;
		for (i = 0; p[i]; i++)
		{
			if (is_delim(p[i], delim))
			p[i] = '\0';
		}
	}

	if (p == NULL || *s == '\0')
		return (NULL);
	result = p;
		i = _strlen(p);
	if (p[i] == '\0' && _strlen(p) > 0)
		space = 1;
	p = p + _strlen(p) + space;

	return (result);
}
