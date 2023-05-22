#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#define MAX_INPUT_LENGTH 1024

/**
 * MAIN - ENTRY POINT
 *
 * Return: always 0
 */
int main(void)
{
	char *prompt = " $ ";
	char input[MAX_INPUT_LENGTH];
	ssize_t nchars_read;
	int ret;

	while (1)
	{
		printf("%s", prompt);
		fflush(stdout);

		nchars_read = read(STDIN_FILENO, input, MAX_INPUT_LENGTH);
		if (nchars_read == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		else if (nchars_read == 0)
		{
			printf("\n");
			break;
		}

		input[nchars_read - 1] = '\0';

		ret = fork();
		if (ret == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (ret == 0)
		{
			char **args = malloc(sizeof(char *) * 2);
			if (args == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}

			args[0] = input;
			args[1] = NULL;
			
			if (execve(input, args, NULL) == -1)
			{
				perror("404");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
