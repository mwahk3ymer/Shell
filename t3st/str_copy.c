#include "main.h"
/**
 * _strcpy - Copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @dest: Copy source to this buffer.
 * @src: This is the source to copy.
 * Return: Copy of original source.
 */

char *_strcpy(char *dest, char *src)
{
	int i, len;

	for (len = 0; src[len] != '\0'; len++)
		;

	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}
