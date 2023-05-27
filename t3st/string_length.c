#include "main.h"

/**
 * _stringlength - returns string
 * @s: pointer to
 *
 * Return: len of str
 */
size_t _stringlength(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}
