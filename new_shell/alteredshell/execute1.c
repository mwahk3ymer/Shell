#include "main.h"
/**
* execmd - executes command
* @argv: arguments used
* Return: always returns 0
*/

void execmd(char **argv)
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

execve(argv[0], argv, NULL);
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
