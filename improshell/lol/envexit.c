#include "main.h"

/**
  *_printenv - Prints variables in current
  * working environment.
  * Return: void.
  */
void _printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		i++;
	}
}

/**
 * _isBuiltIn - Checks if token is a built in.
 * @str: Pointer to string to check.
 * Return: 0 if true else 1.
 */
int _isBuiltIn(char *str)
{
	/* check if strings are equal */
	if ((_strcmp(str, "env")) == 0)
	{
		return (0);
	}
	if ((_strcmp(str, "exit")) == 0)
		return (0);
return (1)
}
