#include "main.h"
/**
 *ctrlc - Control C handler.
 *@signum: The signal number received.
 *
 *Return: Void.
 */
void ctrlc(int signum)
{
	(void)signum;

	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}
