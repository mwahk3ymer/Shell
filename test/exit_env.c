#include "main.h"
/**
 * printenv - prints env
 * @envp: env var
 */
void printenv (char *envp[])
{
	int i = 0;

	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
}
/**
 * builtin_exit - exits
 */
void builtin_exit()
{
	printf("exiting shell..\n");
	exit(0);
}
