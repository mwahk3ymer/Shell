#include "main.h"

#define BUFFER_SIZE 1024

/**
 * execute_comm - executes
 * @cmd: command
 *
 * Return: 1 on succes
 */
int execute_comm(char *cmd)
{
	pid_t child_pid;
	int status = 0;
	char *args[2];

	args[0] = cmd;
	args[1] = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork error");
		return (0);
	}
	if (child_pid == 0)
	{
		if (execve(cmd, args, NULL) == -1)
		{
			perror("Execve error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	return (1);
}

/**
 * main - entry point
 * description: displays prompt
 *
 * Return: 0 always
 */

int main(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t chars;

	while (1)
	{
		printf("$ ");
		chars = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (chars == EOF)
		{
			printf("\n");
			break;  /* End of file, exit the shell */
		}
		if (chars > 0 && buffer[chars - 1] == '\n')
			buffer[chars - 1] = '\0';  /* Remove the newline character */

		if (access(buffer, X_OK) == 0)
		{
			if (!execute_comm(buffer))
			{
				fprintf(stderr, "failed to execute cmd: %s\n", buffer);
			}
		}
		else
		{
			fprintf(stderr, "Command not found: %s\n", buffer);
		}
	}

	return (0);

}
