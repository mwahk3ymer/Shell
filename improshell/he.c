#include "main.h"

/**
 * read_input - reads a line of input
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
 * tokenize_input - tokenizes a line of input into arguments
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

    return (args);
}

/**
 * free_arguments - frees the memory allocated for arguments
 * @args: array of pointers to arguments
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
 * execmd - executes the command
 * @argv: array of arguments
 * @path: PATH environment variable
 */
void execmd(char **argv, char *path)
{
    if (argv && argv[0])
    {
        char *pathname = NULL;
        if (argv[0][0] != '/')
        {
		int i;
		int num_tokens = 0;
		char **path_tokens = tokenize_input(path, ":", &num_tokens);
		for (i = 0; path_tokens[i]; i++)
		{
                char *temp_path = strdup(path_tokens[i]);
                char *temp_argv = strdup(argv[0]);
                pathname = malloc(strlen(temp_path) + strlen(temp_argv) + 2);
                sprintf(pathname, "%s/%s", temp_path, temp_argv);
                free(temp_path);
                free(temp_argv);
                if (access(pathname, X_OK) == 0)
                    break;
                free(pathname);
                pathname = NULL;
		}
            free_arguments(path_tokens, num_tokens);
        }
        else
        {
            pathname = strdup(argv[0]);
        }

        if (pathname == NULL || access(pathname, X_OK) != 0)
        {
            perror("command not found");
        }
        else
        {
            pid_t pid = fork();

            if (pid == -1)
            {
                perror("fork");
                exit(1);
            }

            if (pid == 0)
            {
                execve(pathname, argv, environ);
                perror("error");
                exit(1);
            }
            else
            {
                int status;
                waitpid(pid, &status, 0);
            }
        }

        free(pathname);
    }
}


/**
 * main - entry point of the shell program
 * @ac: number of command line arguments
 * @argv: array of command line arguments
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
            write(STDOUT_FILENO, "exiting shell....\n", strlen("exiting shell....\n"));
            break;
        }

        if (nchars_read > 1)
        {
            char **args = tokenize_input(lineptr, delim, &num_tokens);

            if (strcmp(args[0], "env") == 0)
	    {
		    print_env(envp);
	    }
	    else if (strcmp(args[0], "exit") == 0)
            {
                built_in_exit();
            }
            else
            {
                char *path = getenv("PATH");
                execmd(args, path);
            }
            free_arguments(args, num_tokens);
        }
    }

    free(lineptr);

    return (0);
}

