#include "main.h"
/**
 * builtin - checks if token is there
 * @str: pointer
 *
 * Return: rxit
 */
int builtin(const char *str)
{
	if (strcmp(str, "env") == 0)
		return (0);
	if (strcmp(str, "exit") == 0)
		return (0);
	return (1);
}

/**
 * execbuiltin - exexecutes
 * @tokens: double pointer
 *
 * Return: return 0 or 1
 */

int execbuiltin(char **tokens)
{
	if (strcmp(tokens[0], "env") == 0)
	{
		printenv();
		return (0);
	}
	else if (strcmp(*tokens, "exit") == 0)
	{
		exit(tokens);
		return (0);
	}
	return (1);
}
