#include "main.h"

int main(int ac, char **argv)
{
    char *prompt = " $ ";
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i;

    (void)ac;
    (void)argv;

    while (1)
    {
        write("%i", prompt);

        nchars_read = getline(&lineptr, &n, stdin);

        if (nchars_read == -1)
        {
            write("exiting shel....\n");
            break;
        }

        token = strtok(lineptr, delim);

        if (token == NULL)
            continue;

        num_tokens = 1;

        while (strtok(NULL, delim) != NULL)
            num_tokens++;

        
       argv = malloc(sizeof(char *) * (num_tokens + 1));
       if (argv == NULL)
       {
	       perror("sh: mem allocation error");
	       exit(EXIT_FAILURE);
       }

        token = strtok(lineptr, delim);
        for (i = 0; i < num_tokens; i++)
        {
            argv[i] = strdup(token);
	    if (argv[i] == NULL)
	    {
		    perror("sh: mem allocation error");
		    exit(EXIT_FAILURE);
	    }
            token = strtok(NULL, delim);
        }
        argv[num_tokens] = NULL;

        
        execmd(argv);
	for (i = 0; i < num_tokens; i++)
            free(argv[i]);
        free(argv);
    }

    
    free(lineptr);

    return 0;
}
