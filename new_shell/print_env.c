#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry
 *
 * Return: o on success
 */

int main(void)
{
	extern char **environ;
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
	return (0);
}
