#include "main.h"
/**
 * c_atoi - converts a string l to an integer
 * @l: string.
 * Return: Number if success, -1 if string contains non-numbers.
 */

int c_atoi(char *l)
{
	int n = 0;
	unsigned int num = 0;

	while (l[n] != '\0')
	{
	if (l[n] >= '0' && l[n] <= '9'
		num = num * 10 + (l[n] - '0');
	if (l[n] > '9' || l[n] < '0')
		return (-1);
		n++;
}
return (num);
}
