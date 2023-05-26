#include "main.h"

/**
 * _strto_tokens - splits a str
 * @str: pointre
 *
 * Return: pointer to array
 */
char **_strto_tokens(const char *str)
{
	unsigned int i = 0;
	const char delimeter[] = " \t\n";
	unsigned int space = _white_space(str);
	char **tokens = malloc(sizeof(char *) * (space + 2));
	char *token;

	if (!tokens)
	{
		perror("Allocation error");
		exit(1);
	}

	token = strtok((char *)str, delimeter);

	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, delimeter);
	}

	tokens[i] = NULL;
	return (tokens);
}
