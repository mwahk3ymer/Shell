#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \t\n"

/**
 * prompt - Displays the shell prompt
 */
void prompt(void)
{
	printf("$ ");
}

/**
 * execute_command - Executes the given command with arguments
 * @command: The command to execute
 * @args: Array of command arguments
 */
void execute_command(char *command, char **args)
{
	pid_t pid;
	int status;
	
	pid = fork();
		if (pid == 0)
		{
		/* Child process */
			if (execvp(command, args) == -1)
			{
				perror("Error");
											            exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
		{
			/* Fork failed */
			perror("Error");
			exit(EXIT_FAILURE);
		}
		else
		{
			/* Parent process */
			do
			{
				waitpid(pid, &status, WUNTRACED);
												        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
							        }
}

/**
 * parse_command - Parses the command line and returns the command and its arguments
 * @buffer: The command line buffer
 * @command: Pointer to store the command
 * @args: Array to store the command arguments
 */
void parse_command(char *buffer, char **command, char **args)
{
*command = strtok(buffer, TOKEN_DELIMITERS);

if (*command != NULL)
{
int i = 0;
char *token;

args[i++] = *command;

while ((token = strtok(NULL, TOKEN_DELIMITERS)))
{

	args[i++] = token;
}
args[i] = NULL;
}
}

/**
 * main - Entry point of the shell
 *
 * Return: Always 0
 */
int main(void)
{
	char buffer[BUFFER_SIZE];
	char *command;
	char *args[BUFFER_SIZE];
	
	while (1)
	{
		prompt();
		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			printf("\n");
			
			break;
		
		}
		
		parse_command(buffer, &command, args);
		if (command != NULL)
			execute_command(command, args);
	}
	
	return 0;
}
