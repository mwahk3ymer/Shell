#include "main.h"
/**
 * is_equal_delim - Checks if character b is equal to any other character.
 * @b: character.
 * @delim: " "
 * Return: 0 if no match, otherwise 1
 */

int is_equal_delim(char b, const char *delim)
{
	while (delim && *delim)
	{
		if (b == *delim)
		{
			return (1);
		}
		delim++;
	}
return (0);
}

