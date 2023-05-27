#include "main.h"

/**
 * read_input - a line of inpu
 * @lineptr: pointer to buf
 * @n: pointer to size
 *
 * Return: num ofchar
 */
ssize_t read_input(char **lineptr, size_t *n)
{
	const char *prompt = " $ ";

	write(STDERR_FILENO, prompt, strlen(prompt));
	return (getline(lineptr, n, stdin));
}

/**
 * tokenize_input - a line of input t args.
 * @line: input line
 * @delim: delimiter
 * @num_tokens: pointer
 *
 * Return: array
 */
char **tokenize_input(char *line, const char *delim, int *num_tokens)
{
	char *token;
	char **args = NULL;
	*num_tokens = 0;

	token = strtok(line, delim);

	while (token != NULL)
	{
		/*skip token if its "/bin/ls -l"*/
		if (strcmp(token, " -l") == 0)
		{
			perror("error:");
		}
		else
		{
		args = realloc(args, sizeof(char *) * (*num_tokens + 1));
		if (args == NULL)
		{
			perror("sh: mem allocation error");
			exit(EXIT_FAILURE);
		}
		args[(*num_tokens)++] = strdup(token);
		}
		token = strtok(NULL, delim);
	}
	args = realloc(args, sizeof(char *) * (*num_tokens + 1));
	if (args == NULL)
	{
		perror("sh: mem allocation error");
		exit(EXIT_FAILURE);
	}


	return (args);
}

/**
 * free_arguments - mem allocated for args
 * @args: array of pointere
 * @num_tokens: num of toks
 *
 */
void free_arguments(char **args, int num_tokens)
{
	int i;

	for (i = 0; i < num_tokens; i++)
	{
		free(args[i]);
	}
	free(args);
}

/**
 * main - entry of shell prog
 * @ac: num of cli ac
 * @argv: array of args
 *
 * Return: exit stautsus.
 */
int main(int ac, char **argv)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0;

	(void)ac;
	(void)argv;

	while (1)
	{
		nchars_read = read_input(&lineptr, &n);

		if (nchars_read == -1)
		{
			write(STDOUT_FILENO, "exiting shell....\n", strlen("exiting shell....\n"));
			break;
		}

		if (nchars_read > 1)
		{
			char **args = tokenize_input(lineptr, delim, &num_tokens);

			if (strcmp(args[0], "exit") == 0)
			{
				free_arguments(args, num_tokens);
				break;
			}
			else if (strcmp(args[0], "env") == 0)
			{
				print_env();
			}
			else
			{
			execmd(args);
			}
			free_arguments(args, num_tokens);
		}
	}

	free(lineptr);

	return (0);
}
