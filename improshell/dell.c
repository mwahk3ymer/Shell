#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * read_input - read a line of input
 * @lineptr: pointer to buffer
 * @n: pointer to size
 *
 * Return: number of characters read
 */
ssize_t read_input(char **lineptr, size_t *n)
{
    const char *prompt = " $ ";

    write(STDERR_FILENO, prompt, strlen(prompt));
    return (getline(lineptr, n, stdin));
}

/**
 * tokenize_input - tokenize a line of input into arguments
 * @line: input line
 * @delim: delimiter
 * @num_tokens: pointer to store the number of tokens
 *
 * Return: array of arguments
 */
char **tokenize_input(char *line, const char *delim, int *num_tokens)
{
    char *token;
    char **args = NULL;
    *num_tokens = 0;

    token = strtok(line, delim);

    while (token != NULL)
    {
        args = realloc(args, sizeof(char *) * (*num_tokens + 1));
        if (args == NULL)
        {
            perror("sh: mem allocation error");
            exit(EXIT_FAILURE);
        }
        args[(*num_tokens)++] = strdup(token);
        token = strtok(NULL, delim);
    }

    args = realloc(args, sizeof(char *) * (*num_tokens + 1));
    if (args == NULL)
    {
        perror("sh: mem allocation error");
        exit(EXIT_FAILURE);
    }

    return args;
}

/**
 * free_arguments - free memory allocated for arguments
 * @args: array of pointers
 * @num_tokens: number of tokens
 */
void free_arguments(char **args, int num_tokens)
{
    int i;
    for (i = 0; i < num_tokens; i++)
    {
        free(args[i]);
    }
    free(args);
}

/**
 * execmd - execute a command
 * @argv: arguments array
 * @envp: environment variables array
 */
void execmd(char **argv, char **envp)
{
    if (argv && argv[0])
    {
        pid_t pid;
        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }

        if (pid == 0)
        {
            execve(argv[0], argv, envp);
            perror("error");
            exit(1);
        }
        else
        {
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

/**
 * print_environment - print current environment variables
 * @envp: environment variables array
 */
void print_environment(char **envp)
{
    char **env = envp;

    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}

/**
 * exit_shell - exit the shell
 */
void exit_shell(void)
{
    printf("Exiting shell...\n");
    exit(0);
}

/**
 * main - entry point of the shell program
 * @ac: number of command-line arguments
 * @argv: array of command-line arguments
 * @envp: environment variables array
 *
 * Return: exit status
 */
int main(int ac, char **argv, char **envp)
{
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";
    int num_tokens = 0;

    (void)ac;
    (void)argv;

    while (1)
    {
        nchars_read = read_input(&lineptr, &n);

        if (nchars_read == -1)
        {
            printf("Exiting shell...\n");
            break;
        }

        if (nchars_read > 1)
        {
            char **args = tokenize_input(lineptr, delim, &num_tokens);

            if (strcmp(args[0], "env") == 0)
            {
                print_environment(envp);
            }
            else if (strcmp(args[0], "exit") == 0)
            {
                exit_shell();
            }
            else
            {
                char **env_path = envp;
                char *command_path = NULL;
                int found = 0;

                while (*env_path != NULL)
                {
                    if (strncmp(*env_path, "PATH=", 5) == 0)
                    {
                        command_path = *env_path + 5;
                        found = 1;
                        break;
                    }
                    env_path++;
                }

                if (found)
                {
                    char *token;
                    char *temp_path = strdup(command_path);

                    token = strtok(temp_path, ":");

                    while (token != NULL)
                    {
                        char *executable_path = malloc(strlen(token) + strlen(args[0]) + 2);
                        sprintf(executable_path, "%s/%s", token, args[0]);

                        if (access(executable_path, X_OK) == 0)
                        {
                            args[0] = executable_path;
                            execmd(args, envp);
                            break;
                        }

                        free(executable_path);
                        token = strtok(NULL, ":");
                    }

                    free(temp_path);
                }

                if (!found || command_path == NULL)
                {
                    printf("%s: command not found\n", args[0]);
                }
            }

            free_arguments(args, num_tokens);
        }
    }

    free(lineptr);

    return 0;
}

