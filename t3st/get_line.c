#include "main.h"
/**
 * read_line - Reads input line from the command line as a string.
 * Return: Pointer to the line(string).
 */
char *read_line(void)
{
	char *lineOfInput = NULL;
	size_t lengthOfInput = 0;
	ssize_t charsNum = 0;

	charsNum = getline(&lineOfInput, &lenOfInput, stdin);
	if (lineOfInput == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(lineOfInput);
		exit(-1);
	}
	if (charsNum == EOF)
	{
		free(lineOfInput);
		exit(0);
	}

return (lineOfInput);
}
