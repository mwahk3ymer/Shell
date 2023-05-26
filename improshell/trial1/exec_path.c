#include "main.h"
/**
 * exec_path - Executes a
 * @tokens: Split str
 * @path: Path from path_builder fun
 * @args: Program argument
 *
 * Return: o on succes
 */
int exec_path(char **tokens, char *path, char *args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("error: ");
		return (-1);
	}

	if (pid == 0)
	{
		tokens[0] = path;

		if (execve(tokens[0], tokens, NULL) == -1)
		{
			char *err = _strcat(*tokens, ": No such file or dir\n");
			char *erro = _strcat(_strcat(args, ":"), erro);

			write(STDERR_FILENO, erro, _strlen(erro));
			free(tokens);
			exit(EXIT_FAILURE)
		}
		return (EXIT_SUCCESS);
	}

	wait(&status);

	return (EXIT_SUCCESS);
}
