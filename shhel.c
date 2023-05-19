#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * prompt - Displays the shell prompt
 */
void prompt(void)
{
	printf("$ ");
}

/**
 * execute_command - Executes the given command
 * @command: The command to execute
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
					            /* Child process */
					            if (execvp(command, &command) == -1)
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
 *  * main - Entry point of the shell
 *   *
 *    * Return: Always 0
 *     */
int main(void)
{
	    char buffer[BUFFER_SIZE];
	        char *command;

		    while (1)
			        {
					        prompt();

						        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
								        {
										            printf("\n");
											                break;
													        }

							        command = strtok(buffer, " \t\n");
								        if (command != NULL)
										            execute_command(command);
									    }

		        return 0;
}
