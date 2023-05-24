#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 

#define MAX_INPUT_LENGTH 100

extern char **environ;

void printenv()
{
	char **env = environ;
	
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * main - prints env
 *
 * Return: 0 on succes
 */
int main()
{
	
	char prompt[] = " $ "; 
	char command[MAX_INPUT_LENGTH]; 

	
	while (1)
	{
		printf ("%s", prompt);

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

    return 0;
}
