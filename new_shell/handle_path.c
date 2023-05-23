#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 100
#define MAX_PATH_LENGTH 100

/**
 * get_command_path - Retrieves the full path of a command from the PATH environment variable
 * @command: The command to find in the PATH
 *
 * Return: The full path of the command if found, NULL otherwise
 */
char *get_command_path(const char *command)
{
	char *path = getenv("PATH");
	char *path_entry = strtok(path, ":");

	while (path_entry != NULL)
	{
	char command_path[MAX_PATH_LENGTH];
	snprintf(command_path, sizeof(command_path), "%s/%s", path_entry, command);

	if (access(command_path, X_OK) == 0)
	return strdup(command_path);

	path_entry = strtok(NULL, ":");
	}
	return NULL;
}

/**
 * execute_command - Executes a command in a separate process
 * @command: The command to execute
 *
 * Return: Nothing
 */
void execute_command(const char *command)
{
	if (strcmp(command, "exit") == 0)
	{
	printf("Exiting the shell...\n");
	exit(0);
	}
	else if (strcmp(command, "env") == 0)
	{
	/* Code for printing current environment variables */
	printf("Printing current environment...\n");
	}
	else
	{
	char *command_path = get_command_path(command);
	if (command_path != NULL)
	{
	pid_t child_pid = fork();
	if (child_pid == 0)
	}		/* Child process */
	if (execve(command_path, NULL, NULL) == -1)
	{
		perror("Error executing command");
		exit(1);
	}
}
else if (child_pid < 0)
{
perror("Error forking process");
}
else
{
													/* Parent process */
																																				int child_status;
																																								waitpid(child_pid, &child_status, 0);
																																											}

																														free(command_path);
																																}
													else
																{
																				printf("Command not found: %s\n", command);
																						}
														}
}

/**
 *  * main - Entry point of the shell program
 *   *
 *    * Return: 0 on success
 *     */
int main(void)
{
		char input[MAX_INPUT_LENGTH];

			while (1)
					{
								printf("$ ");

										if (fgets(input, sizeof(input), stdin) == NULL)
													{
																	printf("\n");
																				break; /* Handle end of file (Ctrl+D) */
																						}

												/* Remove trailing newline character */
												input[strcspn(input, "\n")] = '\0';

														char *token = strtok(input, " ");

																while (token != NULL)
																			{
																							execute_command(token);
																										token = strtok(NULL, " ");
																												}
																	}

				return 0;
}
