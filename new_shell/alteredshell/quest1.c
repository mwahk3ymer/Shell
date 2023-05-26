#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * main - Entry point for the shell program.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char *prompt = "$ ";
	char buffer[BUFFER_SIZE];
	char *token;
	int status;

	while (1)
	{
		printf("%s", prompt);

		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		token = strtok(buffer, " ");

		if (token == NULL)
			continue;

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			/* Child process */
			if (execve(token, &token, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* Parent process */
			wait(&status);
		}
	}

	return (0);
}
