#include "main.h"
/**
 * print_environment - print current environment variables
 * @envp: environment variables array
 */
void print_env(char *envp[])
{
    int i = 0;

    while (envp[i] != NULL)
    {
        printf("%s\n", envp[i]);
        i++;
    }
}

/**
 * built_in_exit - exit the shell
 */
void built_in_exit(void)
{
    printf("Exiting shell...\n");
    exit(0);
}
