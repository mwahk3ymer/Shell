#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ; 

void print_environment()
{
    char **env = environ;

    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}

int main()
{
    char prompt[100];
    char command[100];

    printf("Enter prompt: ");
    fgets(prompt, sizeof(prompt), stdin);
    prompt[strcspn(prompt, "\n")] = '\0';

    while (1)
    {
        printf("%s", prompt);

        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "env") == 0)
        {
            print_environment();
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
