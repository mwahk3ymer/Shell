#include <stdio.h>

/**
 * main - prints env
 *
 * Return: 0 on succes
 */
int main(int ac, char **av, char **env)
{
	unsigned int i;
	(void)ac;
	(void)av;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
