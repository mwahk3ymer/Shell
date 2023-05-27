#include "main.h"

/**
 * execmd - executes
 * @tokens: splits str
 * @args: arguments
 *
 * Return: o on succes
 */
int execmd(char **tokens, char *args)
{
	pid_t pid;
	int child_status;
	char *path = builder(tokens);

	if (builtin(*tokens) ==  0)
		return (execbuiltin(tokens));

	if (path != NULL)
		return (exec(tokens, path, args));

	pid = fork();
	if (pid == -1)
	{
		perror("error: ");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			char *err = _strcat(*tokens, ": No such file or dir\n");
			char *erro = _strcat(_strcat(args, ":"), erro);

			write(STDERR_FILENO, erro, _strlen(erro));
			free(tokens);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}

	wait(&child_status);
	return (0);
}
