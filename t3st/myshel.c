#include "main.h"

/**
 * read_input - reads line of input
 *
 * Return: pointer
 */
char *read_input(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t chars;

	chars = getline(&line, &bufsize, stdin);

	if (chars == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}

/**
 * prompt - display prompt
 *
 * Return: void
 */
void prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}

/**
 * main - entry to shell
 * @ac: num of args
 * @argv: pointer to array of ag
 *
 * Return: alwasy 0 if succes
 */

int main(int ac, char *argv[])
{
	char *line;
	int status;
	char **tokens;

	(void)ac;

	signal(SIGINT, ctrlc);
	status = 0;
	while (1)
	{
		prompt();

		line = read_input();
		if (strcmp(line, "\n") == 0)
		{
			free(line);
			continue;
		}
		tokens = strtotokens(line);
		if (tokens[0] == NULL)
		{
			free(tokens);
			free(line);
			continue;
		}

		if (strcmp(tokens[0], "exit") == 0)
		{
			status = exits_sh(tokens, line);
			break;
		}
		else
		{
			status = execmd(tokens, argv[0]);
		}
		free(line);
		free(tokens);
	}

	return (status);
}
