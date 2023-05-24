#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int main(void)
{
    char *path = getenv("PATH");
    char *dir;
    char *delimiter = ":";
    char command[MAX_COMMAND_LENGTH];
    char commandPath[MAX_COMMAND_LENGTH + 1];
    int found = 0;

    dir = strtok(path, delimiter);

    while (1)
    {
        printf(":) ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0)
        {
            printf("Exiting shell...\n");
            break;
        }

        found = 0;

        while (dir != NULL)
        {
            
            snprintf(commandPath, sizeof(commandPath), "%s/%s", dir, command);

            if (access(commandPath, X_OK) == 0)
            {
                printf("Command found: %s\n", commandPath);
                char *args[] = {command, NULL};  /* Example arguments for the command */

                if (execve(commandPath, args, NULL) == -1)
                {
                    perror("Error executing command");
                    return 1;
                }

                found = 1;
                break;
            }

            dir = strtok(NULL, delimiter);
        }

        if (!found)
            printf("Command not found\n");

        dir = strtok(path, delimiter);
    }

    return 0;
}
