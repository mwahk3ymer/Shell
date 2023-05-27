#include "main.h"

/**
 * _puts - prints
 * @str: pointer
 */
void _puts(const char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	_putchar('\n');
}
