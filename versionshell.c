#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_COMMAND_LENGTH 256

int main(void)
{
	char *path = getenv("PATH");
	char *dir;
	char *delimiter = ":";
	char command[256];
	
	dir = strtok(path, delimiter);
	
	printf(":) ");
        fgets(command, sizeof(command), stdin);
	command[strcspn(command, "\n")] = '\0';


	while (dir != NULL)
	{
	char commandPath[256];
	snprintf(commandPath, sizeof(commandPath), "%s/%s", dir, command);
	if (access(commandPath, X_OK) == 0)
	 {
	  printf("Command found: %s\n", commandPath);
	           
	  char *args[] = {command, NULL};  /* Example arguments for the command*/

    	 if (execve(commandPath, args) == -1) 
	 {  
	         perror("Error executing command");
	         return (1);
	  }
	                                                                                                         dir = strtok(NULL, delimiter);
	                                                                                                 }
	                fprintf(stderr, "Command not found\n");
	     return (1);
	                                                                                                                                                                                                }
