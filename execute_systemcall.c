#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *binaryPath = "/path/to/program";
	char *args[] = {binaryPath, "arg1", "arg2", NULL};
        char *envp[] = {NULL};

if (execve(binaryPath, args, envp) == -1)
{
perror("Error executing program");
return (1);
}

return (0);
}
