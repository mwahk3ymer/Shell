#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

#define MAX_INPUT_LENGTH 100
/**
 * printenv - printsenvy
 *
 */

void printenv(void)
{

char **env = environ;
while (*env != NULL)
{
write(STDOUT_FILENO, *env, strlen(*env));
write(STDOUT_FILENO, "\n", 1);
env++;
}
}

/**
 * main - prints env
 * @ac: argumentss
 * @argv: arguments
 * Return: 0 on succes
 */
int main(int ac, char **argv)
{
char prompt[] = " $ ";
char command[MAX_INPUT_LENGTH];
(void)ac;
(void)argv;


while (1)
{
printf("%s", prompt);

fgets(command, sizeof(command), stdin);
command[strcspn(command, "\n")] = '\0';
if (strcmp(command, "env") == 0)
{
printenv();
}
else if (strcmp(command, "exit") == 0)
{
printf("Exiting shell...\n");
break;
}
else
{
printf("Unknown command: %s\n", command);
}
}

return (0);
}
