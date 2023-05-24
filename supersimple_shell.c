#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
/**
 * main - example
 *
 * Return: Always 0.
 */

int main(void)
{
	/*char *prompt = " $ ";*/
	char command[MAX_COMMAND_LENGTH];
	char *binaryPath;

	while (1)
	{
		printf("shell> ");
		fgets(command, MAX_COMMAND_LENGTH, stdin);

		/*remove newline from command*/
		command[strcspn(command, "\n")] = '\0';
		/*exit if user enters exit*/
		if (strcmp(command, "exit") == 0)
			break;

		/* Fork a new process*/
	       	pid_t pid = fork();

		if (pid == -1)
		{
			/*child process*/
			binaryPath = command;
			execl(binaryPath, binaryPath, NULL);
			perror("Error executing command");
			exit(1);

		}
		else
		{
			/*parent*/
			int status;
			waitpid(pid, &status, 0);

			if (WIFEXITED(status))
			{
				int exit_status = WEXITSTATUS(status);
				printf("Child process terminated with exit status: %d\n", exit_status);
			}
			else if (WIFSIGNALED(status))
			{
				int signal_number = WTERMSIG(status);
				printf("Child process terminated due to signal: %d\n", signal_number);
			}
		}
	}
	return (0);
}
