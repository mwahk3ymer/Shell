#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 

#define MAX_INPUT_LENGTH 100

void execute_command(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		printf("exiting shell..\n");
		exit(0);
	}

	else if (strcmp(command, "env") == 0)
	{
		printf("prints current environment..\n");
	}
	else
	{
	printf("unknown cd: %s\n", command);
	}
}

int main()
{
	char input[MAX_INPUT_LENGTH];

	while (1) 
	{
		printf ("$ ");
		
		if (fgets(input, sizeof(input), stdin) == NULL)
		{ 
			printf("\n");
			break;
		}

		input[strcspn(input,"\n")] = '\0';
		
		execute_command(input);
	}

	return (0);
}
