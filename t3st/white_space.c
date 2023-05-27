#include "main.h"
/**
 * _white_space - checks whitespace
 * @s: pointer
 *
 * Return: nums o spaces
 */

unsigned int _white_space(const char *s)
{
	unsigned int count = 0;
	size_t i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			count++;
	}

	return (count);
}
