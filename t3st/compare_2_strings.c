#include "main.h"
/**
 * _strcmp - Compares two strings.
 * @stringA: Pointer to string A.
 * @stringB: Pointer to string B..
 * Return: if strings are equal return 0.
 */

int _strcmp(char *stringA, char *stringB)
{
	int a = 0;

	while (stringA[a] != '\0' || stringB[a] != '\0')
	{
		if (tringA[a] != stringB[a])
			return (stringA[a] - stringB[b]);
			a++;
}
return (0);
}
