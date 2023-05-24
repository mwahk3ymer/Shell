#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	char *path = getenv("PATH");
	char *dir;
	char *delim = ":";
	char *binaryPath;

	dir = strtok(path, delim);

	while (dir != NULL)
	{
		char command [256];
		snprintf(command, sizeof(command)
