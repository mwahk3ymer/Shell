#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \t\n"
#define PATH_DELIMITER ":"

/**
 *  * prompt - Displays the shell prompt
 *   */
void prompt(void)
{
	    printf("$ ");
}

/**
 *  * execute_command - Executes the given command with arguments
 *   * @command: The command to execute
 *    * @args: Array of command arguments
 *     * @path: The PATH environment variable
 *      */
void execute_command(char *command, char **args, char *path)
{
	    char *full_path;
	        pid_t pid;
		    int status;

		        if (access(command, F_OK) == 0)
				    {
					            /* Command exists in the current directory */
					            full_path = command;
						        }
			    else
				        {
						        /* Search for the command in the PATH */
						        char *token;

							        token = strtok(path, PATH_DELIMITER);
								        while (token)
										        {
												            full_path = malloc(strlen(token) + strlen(command) + 2);
													                sprintf(full_path, "%s/%s", token, command);

															            if (access(full_path, F_OK) == 0)
																	                    break;

																                free(full_path);
																		            full_path = NULL;

																			                token = strtok(NULL, PATH_DELIMITER);
																					        }
									    }

			        if (full_path == NULL)
					    {
						            printf("%s: command not found\n", command);
							            return;
								        }

				    pid = fork();
				        if (pid == 0)
						    {
							            /* Child process */
							            if (execv(full_path, args) == -1)
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

						    free(full_path);
}

/**
 *  * parse_command - Parses the command line and returns the command and its arguments
 *   * @buffer: The command line buffer
 *    * @command: Pointer to store the command
 *     * @args: Array to store the command arguments
 *      */
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
 *  * main - Entry point of the shell
 *   *
 *    * Return: Always 0
 *     */
int main(void)
{
	    char buffer[BUFFER_SIZE];
	        char *command;
		    char *args[BUFFER_SIZE];
		        char *path = getenv("PATH");

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
											            execute_command(command, args, path);
										    }

			        return 0;
}
