#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = " $ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;

	(void)ac;

	while (1)
	{
	printf("%s", prompt);
	nchars_read = getline(&lineptr, &n, stdin);

	if(nchars_read == -1) 
	{
		printf("exiting shel...\n");
		return (-1);
	}

	lineptr_copy = malloc(sizeof(char) * nchars_read);
	if (lineptr_copy== NULL)
	{
		perror("tsh: memory allocation error");
		return (-1);
	}
	strcpy(lineptr_copy, lineptr);

	token = strtok(lineptr, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	argv = malloc(sizeof(char *) * num_tokens);
	token = strtok(lineptr_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(argv[i], token);

		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	printf("%s\n", lineptr);

	execmd(argv);
	
	if (lineptr != NULL)
	{
		free(lineptr);
		lineptr = NULL;
	}
	if (lineptr_copy != NULL)
	{
		free(lineptr_copy);
		lineptr_copy = NULL;
	}
	
	for (i = 0; i < num_tokens - 1; i++)
	{
		if (argv[i] != NULL)
		{
			free(argv[i]);
			argv[i] = NULL;
		}
	}
	}
	if (lineptr != NULL)
	{
		free(lineptr);
	}
	if (argv != NULL)
	{
		free(argv);
	}

	return (0);
}
