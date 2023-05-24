#include "main.h"

void execmd(char **argv)
{
    if (argv && argv[0])
    {
        /* Fork a child process */
        pid_t pid;
        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }

        if (pid == 0)
        {
            /* Child process */
            execve(argv[0], argv, NULL);

            /*  an error occurred */
            perror("error");
            exit(1);
        }
        else
        {
            /* Parent process */
            int status;
            waitpid(pid, &status, 0);
        }
    }
}
