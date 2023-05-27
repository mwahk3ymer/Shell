#include "main.h"
/**
 * exits_sh - exits shekll
 * @tokens: double ponter
 *
 * Return: void
 */
void exits_sh(char **tokens)
{
	if (tokens[i] != NULL)
	{
		write(STDERR_FILENO, "Exit: illegal exit status: ", 28);
		write(STDERR_FILENO, tokens[1], 1);
		write(STDERR_FILENO, "\n", 1);
	}
	free(tokens);
	exit(0);
}
