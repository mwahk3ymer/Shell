#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
 * main - example
 *
 * Return: Always 0.
 */
int main(void)
{

pid_t pid;
const char* command = "/bin/ls";
char* args[] = {"ls", "-l", "/tmp", NULL};
char *envp[] = {NULL};
int status;

for (int i = 0; i < 5; i++)
{
pid = fork();
if (pid < 0)
{
printf("Error:");
return (1);
}
if (pid == 0)
{
printf("child %d executing \n", i);
execve(command, args, envp);
perror("Error:");
exit(1);
}
else
{
wait(&status);
printf("child process with pid: %d\n", pid);
}
}
return (0);
}
