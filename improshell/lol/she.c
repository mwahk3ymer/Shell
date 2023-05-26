#include "main.h"

#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#define MAX_COMMAND_LENGTH 100
void prompt(void)
{
    char *prompt = "#cisfun$ ";
    write(STDOUT_FILENO, prompt, strlen(prompt));
}

int main(void)
{
    char command[MAX_COMMAND_LENGTH];

    while (1)
    {
        write(STDOUT_FILENO, "Your Shell$ ", strlen("Your Shell$ "));

        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
        {
            write(STDOUT_FILENO, "\n", 1);
            break; // Exit the loop on end of file (Ctrl+D)
        }

        command[strcspn(command, "\n")] = '\0'; // Remove the trailing newline character

        if (strcmp(command, "exit") == 0)
        {
            break; // Exit the loop if the user types "exit"
        }

        if (strlen(command) > 0)
        {
            if (system(command) == -1)
            {
                char errorMessage[MAX_COMMAND_LENGTH + 20];
                snprintf(errorMessage, sizeof(errorMessage), "Command not found: %s\n", command);
                write(STDERR_FILENO, errorMessage, strlen(errorMessage));
            }
        }
    }

    write(STDOUT_FILENO, "Exiting Shell...\n", strlen("Exiting Shell...\n"));

    return 0;
}
