#include "main.h"

/**
 * _stringconcat - concates
 * @dest: dest str
 * @src: source str
 *
 * Return: pointer
 */

char *_stringconcat(char *dest, const char *src)
{
	size_t dest_len = _stringlength(dest);
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len++] = src[i];

	dest[dest_len] = '\0';
	return (dest);
}
