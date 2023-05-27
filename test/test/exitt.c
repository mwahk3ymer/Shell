#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/**
 * execute_command - Executes a command in a child process.
 * @command: command
 * Return: If an error occurs - a corresponding error code.
 * O/w - The exit value of the last executed command.
 */
void execute_command(char *command)
{
	if (command == NULL)
	{
		write(STDOUT_FILENO, "invalid cmd\n", strlen("invalid cmd\n"));
		return;
	}

	if (strcmp(command, "exit") == 0)
	{
		write(STDOUT_FILENO, "exiting shell..\n", strlen("exiting shell....\n"));
		exit(0);
	}
	printf("unknown cd: %s\n", command);
}

/**
 * main - Runs a simple UNIX command interpreter.
 * @ac: argument c
 * @argv: arguments
 * Return: always returns 0
 */
int main(int ac, char **argv)
{
	char *prompt = " $ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	(void)ac;
	(void)argv;

	while (1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		nchars_read = getline(&lineptr, &n, stdin);

		if (nchars_read == -1)
		{
			write(STDOUT_FILENO, "exiting shell..\n", strlen("exiting shell....\n"));
			break;
		}

		if (lineptr[nchars_read - 1] == '\n')
		{
			lineptr[nchars_read - 1] = '\0';
		}
		execute_command(lineptr);
	}

	free(lineptr);

	return (0);
}
